function HandleDevice(dev)
	Type	= dev.GetOption("Device", "Type")
	-- Write device specific code here.
	mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
	mq.Push("/CropSchedule/Application/AirMoisture", System.Rand(),"")
	return 0
end


function init(argv)	
	ThisProcess.Register("/DeviceManager/DmAirmoist/Application")
	System.DebugOutput( "DriverManager DmAirmoist here" )

	ThisProcess.SetTimer(4000)

	return 0
end


function proc(evt)
	if evt == "/DeviceManager/DmAirmoist/Application" then
		return 0
	end

	if evt == "/Timer" then
		dm	= System.CreateScriptObject( 'Ceres.DeviceManager' )
		dev	= dm.GetDevice('AirMoisture.Sensor','')
		HandleDevice( dev )
	end

	return 0
end
