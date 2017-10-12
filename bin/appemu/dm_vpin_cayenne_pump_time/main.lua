function HandleDevice(evt, dev)
--	Type	= dev.GetOption("Device", "Type")
	-- Write device specific code here.
	local mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
	local msg		= mq.Pop(evt,"")
	dev.Send(msg,-1,0)
	return 0
end


function init(argv)	
	ThisProcess.Register("/DeviceManager/CayennePumpTime/Application")
	System.DebugOutput( "DriverManager DmVpinPump here" )

	return 0
end


function proc(evt)
	if evt == "/DeviceManager/CayennePumpTime/Application" then
		local dm	= System.CreateScriptObject( 'Ceres.DeviceManager' )
		local dev	= dm.GetDevice('CayennePumpTime','')
		System.DebugOutput("DMVpin PUMP working")
		HandleDevice( evt, dev )
		return 0
	end

	return 0
end
