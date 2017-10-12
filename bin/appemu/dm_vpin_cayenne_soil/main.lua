function HandleDevice(evt,dev)
--	Type	= dev.GetOption("Device", "Type")
	-- Write device specific code here.
	local mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
	
	local msg		= mq.Pop(evt,"")
	--System.DebugOutput("I AM INSIDE CAYENNE SOIL APPLICATION  "..msg)

	dev.Send(msg,-1,0)
	return 0
end


function init(argv)	
	ThisProcess.Register("/DeviceManager/CayenneSoil/Application")
	System.DebugOutput( "DriverManager DmVpinCyenne here" )

	return 0
end


function proc(evt)
	if evt == "/DeviceManager/CayenneSoil/Application" then
		local dm	= System.CreateScriptObject( 'Ceres.DeviceManager' )
		local dev	= dm.GetDevice('CayenneSoil','')
		HandleDevice( evt, dev )
		return 0
	end

	return 0
end
