
function init(argv)
	ThisProcess.Register("/CropSchedule/Application")
	ThisProcess.Register("/CropSchedule/Application/Temperature")
	ThisProcess.Register("/CropSchedule/Application/SoilMoisture")
	ThisProcess.Register("/CropSchedule/Application/AirMoisture")
	System.DebugOutput( "CropSchedule here" )

	return 0
end


function proc(evt)
	mq2		= System.CreateScriptObject( "Ceres.ServiceBus" )
	msg		= mq2.Pop(evt,"")
	System.DebugOutput( evt.." sent "..msg )

	mq		= System.CreateScriptObject( "Ceres.ServiceBus" )
	mq.Push("/DeviceManager/DmPump/Application", "","")

	return 0
end

