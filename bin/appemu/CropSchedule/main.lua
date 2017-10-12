function OnEvent(evt)
	System.DebugOutput("Event =============================================="..evt)
	
	local oldstate = fsm.GetCurrentState()
	if oldstate == 'ON' and (os.clock() - starttime) < mintime and evt == 'mos_low' then
		return 
	end	
	local state = fsm.Transition(evt)
	System.DebugOutput( state )
	
	if state == 'ON' and oldstate ~= 'ON' then
		local mq = System.CreateScriptObject( "Ceres.ServiceBus" )
		mq.Push("/DeviceManager/DmPump/Application", "high" ,"")
		starttime = os.clock()
		System.DebugOutput ("Start Time = "..starttime)
		System.DebugOutput ("Start date = "..os.date("%c"))
	elseif state == 'OFF' and oldstate == 'ON' then
		local mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
		mq.Push("/DeviceManager/DmPump/Application", "low" ,"")
		mq.Push("/DeviceManager/CayennePumpTime/Application", (os.clock() - starttime)..",Duration,sec","")
		System.DebugOutput("DUration of pump "..os.clock() - starttime)
		System.DebugOutput ("end date = "..os.date("%c"))
		starttime = 0
	end
	
end


function run_regulator(regulator, fsm)
	--if regulator ~= "SoilMoisture" then
	--	return
	--end

	fsm	= ThisProcess.GetObject(regulator..".FSM")
	fsm.SetCurrentState("START")

end


function set_next_schedule()
	schedulestarttime =os.time({year = tonumber(os.date("%Y")), month = tonumber(os.date("%m")), day = tonumber(os.date("%d")),hour = string.sub(schedulestart,1,2),min = string.sub(schedulestart,4,5), sec=0})
	scheduleendtime =os.time({year = tonumber(os.date("%Y")), month = tonumber(os.date("%m")), day = tonumber(os.date("%d")),hour = string.sub(scheduleend,1,2),min = string.sub(scheduleend,4,5), sec=0})
	if schedulestarttime <= os.time() then  
		nextiteration = math.floor(math.floor(os.difftime(os.time(),schedulestarttime)/3600)/scheduleinterval) + 1 
		nextscheduletime = schedulestarttime+ nextiteration*scheduleinterval*3600  
			
	else
		nextscheduletime = schedulestarttime
	end
	if nextscheduletime > scheduleendtime then
		nextscheduletime = schedulestarttime + 24 * 3600 
	end	
end				



function load_regulator(regulator)
	section	= "Regulator." .. regulator
	model	= ThisProcess.GetSetting(section, "Model", "")
	data	= ThisProcess.GetSetting(section, "ModelData", "")
	fsmfile	= ThisProcess.GetSetting(section, "StateMachine", "")
	if model ~= "" then 
		model = ThisProcess.CreateGlobalObject(model, regulator..".Model", "") 	
		if data ~= "" then
			model.Load(data, '')
		end	
	end
	
	if fsmfile ~= "" then 
		fsm	= ThisProcess.CreateGlobalObject("System.StateMachine", regulator..".FSM", "") 
		fsm.Load( fsmfile, "" )
	end

	run_regulator( regulator, fsm )
end



function init(argv)
 	ThisProcess.Register("/CropSchedule/Application")
	ThisProcess.Register("/CropSchedule/Application/Temperature")
	ThisProcess.Register("/CropSchedule/Application/SoilMoisture")
	ThisProcess.Register("/CropSchedule/Application/CayenneMode")
	ThisProcess.Register("/CropSchedule/Application/CayennePump")

	System.DebugOutput( "CropSchedule here" )
	maxtime = 300
	mintime = 10
	starttime = 0
	hightemp = 50
	highmos = 10000
	mode = 0
	--schedulefrequency = 3  
	-- Schedule frequency in a day 
	scheduleinterval = 4   
	-- Time interval in hour between schedule frequencies 
	schedulestart = "06:00"
	-- Start time of Day "6 a.m " 
	scheduleduration = 60 
	-- In second
	scheduleend = "19:00"
	-- Schedule end time of day

--	regulators = System.CreateScriptObject( "List" )
--	System.DebugOutput(ThisProcess.GetSetting("Settings", "Regulators", ""))
--	regulators.FromString( ThisProcess.GetSetting("Settings", "Regulators", ""), "," )
--	regulators.FromString("Temperature",",")

--	for n=1,regulators.GetSize() do
--		load_regulator( regulators.GetAt(n) )
		load_regulator( "Temperature" )
		load_regulator( "SoilMoisture" )
--	end
	
	set_next_schedule()
	ThisProcess.SetTimer(1000)
	
	return 0
end


function proc(evt)
	local mq2		= System.CreateScriptObject( "Ceres.ServiceBus" )
	local msg		= mq2.Pop(evt,"")
	--System.DebugOutput( evt.." sent "..msg )

--	mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
--	mq.Push("/DeviceManager/DmPump/Application", "","")
	
	if evt == "/CropSchedule/Application/CayenneMode" then
		mode = tonumber(msg)
		if mode == 1 then
			set_next_schedule()
		end	
	end
	if evt == "/CropSchedule/Application/CayennePump" then
		if tonumber(msg) == 1 then
			OnEvent("manual_on")
		else 
			OnEvent("manual_off")
		end
	end
	





	if evt == "/Timer" then
		if mode == 0 then 
			if starttime > 0 and (os.clock() - starttime) > maxtime then 
				OnEvent("time_out")
			end	
		else
		        System.DebugOutput("=======================================NextScheduleTime"..nextscheduletime)
			if (os.time() - nextscheduletime) >= 0 and (os.time() - nextscheduletime) <= 10 then
				OnEvent("manual_on")
			end
			
			if starttime > 0 and (os.clock() - starttime) > scheduleduration then 
				OnEvent("manual_off")
				set_next_schedule()
			end
		end	

	end
        if evt == "/CropSchedule/Application/SoilMoisture" then
		local mq = System.CreateScriptObject( "Ceres.ServiceBus" )
		mq.Push("/DeviceManager/CayenneSoil/Application", msg..", Moisture, Pecrentage","")

		System.DebugOutput( "My Moisture"..msg ) 
		if mode == 0 then 
			if tonumber(msg) < highmos then
				OnEvent( "mos_high" )
			else
				OnEvent( "mos_low" )
			end
		end	
	end
	if evt == "/CropSchedule/Application/Temperature" then
		System.DebugOutput( "My Temperature"..msg )

		local mq = System.CreateScriptObject( "Ceres.ServiceBus" )
		mq.Push("/DeviceManager/CayenneTemp/Application", msg..", TEMPERATURE, CELSIUS","")
		--if mode == 0 then
			--local fn	= ThisProcess.GetObject("Temperature.Model")
			--mintime = fn.Calculate(tonumber(msg))
			--mintime = Math.Interpolator (tonumber(msg))
			--System.DebugOutput("Calutated Min Time Value************************************************************"..mintime)
			
		--end
	end	
	return 0
end 
