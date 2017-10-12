function OnEvent(evt)
	System.DebugOutput("Event ==="..evt)
	--if fsm.HasTransition(evt) ~= 0 then
	--	return		
	--end
	oldstate = fsm.GetCurrentState()
	if oldstate == 'ON' and (os.clock() - starttime) < mintime and evt == 'temp_low' then
		return 
	end	
	state = fsm.Transition(evt)
	System.DebugOutput( state )
	
	if state == 'ON' and oldstate ~= 'ON' then
		mq = System.CreateScriptObject( "Ceres.ServiceBus" )
		mq.Push("/DeviceManager/DmPump/Application", "high" ,"")
		starttime = os.clock()
		System.DebugOutput ("Start Time = "..starttime)

	elseif state == 'OFF' and oldstate == 'ON'  then
		mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
		mq.Push("/DeviceManager/DmPump/Application", "low" ,"")
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




function load_regulator(regulator)
	section	= "Regulator." .. regulator
	model	= ThisProcess.GetSetting(section, "Model", "")
	data	= ThisProcess.GetSetting(section, "ModelData", "")
	fsmfile	= ThisProcess.GetSetting(section, "StateMachine", "")
--	fsmfile = "Temperature.fsm"
	System.DebugOutput( "My File"..fsmfile )
	if model ~= "" then 
		ThisProcess.CreateGlobalObject(model, regulator..".Model", "") 	
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
--	ThisProcess.Register("/CropSchedule/Application/SoilMoisture")
--	ThisProcess.Register("/CropSchedule/Application/AirMoisture")
	System.DebugOutput( "CropSchedule here" )
	maxtime = 120
	mintime = 60
	starttime = 0
	hightemp = 50
	regulators = System.CreateScriptObject( "List" )
--	System.DebugOutput(ThisProcess.GetSetting("Settings", "Regulators", ""))
--	regulators.FromString( ThisProcess.GetSetting("Settings", "Regulators", ""), "," )
--	regulators.FromString("Temperature",",")

--	for n=1,regulators.GetSize() do
		load_regulator( "Temperature" )
--	end

	ThisProcess.SetTimer(1000)

	return 0
end


function proc(evt)
	mq2		= System.CreateScriptObject( "Ceres.ServiceBus" )
	msg		= mq2.Pop(evt,"")
	--System.DebugOutput( evt.." sent "..msg )

--	mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
--	mq.Push("/DeviceManager/DmPump/Application", "","")

	if evt == "/Timer" then
		if starttime > 0 and (os.clock() - starttime) > maxtime then 
			OnEvent("time_out")
		end
	end
        if evt == "/CropSchedule/Application/Temperature" then
         	--float temp = ..msg
		System.DebugOutput( "My Temp"..msg ) 
		if tonumber(msg) > hightemp then
			OnEvent( "temp_high" )
		else
			OnEvent( "temp_low" )
		end
	end
	return 0
end 
