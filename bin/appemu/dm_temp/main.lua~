function HandleDevice(dev)
	--Type	= dev.GetOption("Device", "Type")
	-- Write device specific code here.
	local mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
	--loacl val = dev.Receive(1,0)
	--mq.Push("/CropSchedule/Application/Temperature", val,"")
	mq.Push("/CropSchedule/Application/Temperature", System.RandRange(1,50),"")
	return 0
end


function init(argv)	
	ThisProcess.Register("/DeviceManager/DmTemp/Application")

	ThisProcess.SetTimer(2000)
	
	return 0
end


function proc(evt)
	if evt == "/DeviceManager/DmTemp/Application" then
		return 0
	end

	if evt == "/Timer" then
		local dm	= System.CreateScriptObject( 'Ceres.DeviceManager' )
		local dev	= dm.GetDevice('Temperature.Sensor','')
		HandleDevice( dev )
	end

	return 0
end
