function HandleDevice(dev)
--	Type	= dev.GetOption("Device", "Type")
	-- Write device specific code here.
--	if dev.IsReadPending(10) then
		--local val = dev.Receive(1,0)
		val = 1
		local mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
		mq.Push("/CropSchedule/Application/CayenneMode", val ,"")
--	end
	return 0
end


function init(argv)	
	ThisProcess.Register("/DeviceManager/CayenneMode/Application")

	ThisProcess.SetTimer(2000)
	
	return 0
end


function proc(evt)
	if evt == "/DeviceManager/CayenneMode/Application" then
		return 0
	end

	if evt == "/Timer" then
		local dm	= System.CreateScriptObject( 'Ceres.DeviceManager' )
		local dev	= dm.GetDevice('CayenneMode','')
		HandleDevice( dev )
	end

	return 0
end
