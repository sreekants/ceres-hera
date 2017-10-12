function HandleDevice(evt,dev)
--	Type	= dev.GetOption("Device", "Type")
	-- Write device specific code here.
	local mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
	
	local msg		= mq.Pop(evt,"")
	--System.DebugOutput("I AM INSIDE CAYENNE APPLICATION  "..msg)

	dev.Send(msg,-1,0)
	return 0
end


function init(argv)	
	ThisProcess.Register("/DeviceManager/CayenneTemp/Application")
	System.DebugOutput( "DriverManager DmVpinCyenne here" )

	return 0
end


function proc(evt)
	if evt == "/DeviceManager/CayenneTemp/Application" then
		local dm	= System.CreateScriptObject( 'Ceres.DeviceManager' )
		local dev	= dm.GetDevice('CayenneTemp','')
		HandleDevice( evt, dev )
		return 0
	end

	return 0
end
