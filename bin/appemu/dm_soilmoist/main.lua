function HandleDevice(dev)
	--Type	= dev.GetOption("Device", "Type")
	-- Write device specific code here.
	local mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
	--loacl val = dev.Receive(1,0)
	--mq.Push("/CropSchedule/Application/SoilMoisture", val,"")
	mq.Push("/CropSchedule/Application/SoilMoisture", System.RandRange(1,1024),"")
	return 0
end


function init(argv)	
	ThisProcess.Register("/DeviceManager/DmSoilmoist/Application")
	System.DebugOutput( "DriverManager DmSoilmoist here" )

	ThisProcess.SetTimer(4000)

	return 0
end


function proc(evt)
	if evt == "/DeviceManager/DmSoilmoist/Application" then
		return 0
	end

	if evt == "/Timer" then
		dm	= System.CreateScriptObject( 'Ceres.DeviceManager' )
		dev	= dm.GetDevice('SoilMoisture.Sensor','')
		HandleDevice( dev )
	end

	return 0
end
