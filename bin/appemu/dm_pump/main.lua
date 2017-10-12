function HandleDevice(evt, dev)
	Type	= dev.GetOption("Device", "Type")
	-- Write device specific code here.
	mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
	msg		= mq.Pop(evt,"")
	dev.Send(msg,1,0)
	return 0
end


function init(argv)	
	ThisProcess.Register("/DeviceManager/DmPump/Application")
	System.DebugOutput( "DriverManager DmPump here" )

	return 0
end


function proc(evt)
	if evt == "/DeviceManager/DmPump/Application" then
		dm	= System.CreateScriptObject( 'Ceres.DeviceManager' )
		dev	= dm.GetDevice('Pump','')
		HandleDevice( evt, dev )
		return 0
	end

	return 0
end
