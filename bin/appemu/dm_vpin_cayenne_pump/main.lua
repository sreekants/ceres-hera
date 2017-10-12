function HandleDevice(dev, val)
--	Type	= dev.GetOption("Device", "Type")
	-- Write device specific code here.
	--if dev.IsReadPending(10) then
		--local val = dev.Receive(1,0)
		local val = 0
		local mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
		mq.Push("/CropSchedule/Application/CayennePump", val ,"")
	--end
	return 0
end


function init(argv)	
	ThisProcess.Register("/DeviceManager/CayennePump/Application")

	ThisProcess.SetTimer(20000)

	return 0
end


function proc(evt)
	if evt == "/DeviceManager/CayennePump/Application" then
		return 0
	end

	if evt == "/Timer" then
		local dm	= System.CreateScriptObject( 'Ceres.DeviceManager' )
		local dev	= dm.GetDevice('CayennePump','')
	
-- Test code to alternate pump value		
	--	if val == 0 then
	--		val = 1
	--	else val = 0 
	--	end	

		HandleDevice( dev, val )
	end

	return 0
end


