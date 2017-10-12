
// Modules built into the Node sketch
#include <cos/src/cah/portable/LuaApplicationHost.cpp>
#include <cos/src/cah/portable/modmain.cpp>
#include <cos/src/cdvm/portable/CayenneVirtualPin.cpp>
#include <cos/src/cdvm/portable/AnalogPin.cpp>
#include <cos/src/cdvm/portable/DigitalPin.cpp>
#include <cos/src/cdvm/portable/Device.cpp>
#include <cos/src/cdvm/portable/DeviceManager.cpp>
#include <cos/src/cdvm/portable/FileDevice.cpp>
//#include <cos/src/cdvm/portable/HttpFileDevice.cpp>
//#include <cos/src/cdvm/portable/IoManager.cpp>
#include <cos/src/cdvm/portable/modmain.cpp>
//#include <cos/src/cdvm/portable/MqDevice.cpp>
//#include <cos/src/cdvm/portable/MqttDevice.cpp>
#include <cos/src/cdvm/portable/NullDevice.cpp>
#include <cos/src/cdvm/portable/NullPin.cpp>
#include <cos/src/cdvm/portable/NullVirtualPin.cpp>
//#include <cos/src/cdvm/portable/PowerManager.cpp>
//#include <cos/src/cdvm/portable/SocketDevice.cpp>
#include <cos/src/cfs/portable/ArduinoFileSystem.cpp>
#include <cos/src/cfs/portable/BootFileSystem.cpp>
//#include <cos/src/cfs/portable/DeviceFile.cpp>
//#include <cos/src/cfs/portable/Directory.cpp>
//#include <cos/src/cfs/portable/File.cpp>
#include <cos/src/cfs/portable/FileSystem.cpp>
#include <cos/src/cfs/portable/FilesystemManager.cpp>
#include <cos/src/cfs/portable/FileHandleManager.cpp>
#include <cos/src/cfs/portable/modmain.cpp>
#include <cos/src/cfs/portable/NullFile.cpp>
//#include <cos/src/cfs/portable/PosixFileSystem.cpp>
#include <cos/src/cfs/portable/Redirector.cpp>
//#include <cos/src/cfs/portable/RemoteFile.cpp>
//#include <cos/src/cfs/portable/SerialPortFile.cpp>
//#include <cos/src/cfs/portable/SymbolicLink.cpp>
//#include <cos/src/cfs/portable/Win32FileSystem.cpp>
#include <cos/src/cfs/portable/HttpDirectory.cpp>
#include <cos/src/cfs/portable/HttpFile.cpp>
#include <cos/src/cfs/portable/HttpFileServerConnection.cpp>
#include <cos/src/cfs/portable/HttpFileSystem.cpp>

#include <cos/src/cipc/portable/Event.cpp>
//#include <cos/src/cipc/portable/IPCPort.cpp>
//#include <cos/src/cipc/portable/IPCService.cpp>
//#include <cos/src/cipc/portable/IPCServiceThread.cpp>
//#include <cos/src/cipc/portable/IPCSocket.cpp>
#include <cos/src/cipc/portable/MQ.cpp>
#include <cos/src/cipc/portable/MQBroker.cpp>
#include <cos/src/cipc/portable/ServiceBus.cpp>
#include <cos/src/cipc/portable/Topic.cpp>
#include <cos/src/cnm/portable/InternetGateway.cpp>
#include <cos/src/cnm/portable/NetworkManager.cpp>
#include <cos/src/com/portable/modmain.cpp>
#include <cos/src/com/portable/ObjectFactory.cpp>
#include <cos/src/com/portable/ObjectManager.cpp>
#include <cos/src/com/portable/ObjectNode.cpp>
// #include <cos/src/cpm/portable/Fabric.cpp>
// #include <cos/src/cpm/portable/FabricPriorityArray.cpp>
// #include <cos/src/cpm/portable/FabricRunQueue.cpp>
// #include <cos/src/cpm/portable/Fiber.cpp>
// #include <cos/src/cpm/portable/FiberProgram.cpp>
// #include <cos/src/cpm/portable/FiberScheduler.cpp>
#include <cos/src/cpm/portable/FirmwareManager.cpp>
#include <cos/src/cpm/portable/PackageManager.cpp>
#include <cos/src/cpm/portable/ProcessManager.cpp>
#include <cos/src/cpm/portable/Registry.cpp>
#include <cos/src/cpm/portable/Task.cpp>
#include <cos/src/cpm/portable/ScriptTask.cpp>
#include <cos/src/creg/portable/RegConfigParser.cpp>
#include <cos/src/creg/portable/RegSimpleConfigParser.cpp>
//#include <cos/src/csec/portable/modmain.cpp>
#include <cos/src/csec/portable/SecurityManager.cpp>
#include <cos/src/csm/portable/DataLogger.cpp>
#include <cos/src/csm/portable/StorageManager.cpp>
#include <cos/src/cvm/portable/ApplicationHost.cpp>
#include <cos/src/cvm/portable/ApplicationManifest.cpp>
#include <cos/src/kernl/portable/BootLoader.cpp>
#include <cos/src/kernl/portable/Ceres.cpp>
#include <cos/src/kernl/portable/CloudService.cpp>
#include <cos/src/kernl/portable/ConfigurationDatabase.cpp>
#include <cos/src/kernl/portable/Kernel.cpp>
#include <cos/src/kernl/portable/KernelProcess.cpp>
#include <cos/src/kernl/portable/ModuleFactory.cpp>
#include <cos/src/kernl/portable/ModuleManager.cpp>
#include <cos/src/kernl/portable/Subsystem.cpp>
#include <cos/src/kernl/portable/SystemInformation.cpp>
#include <cos/src/kernl/portable/MountedFileSystem.cpp>
//#include <cos/src/kernl/portable/Timer.cpp>
//#include <cos/src/kernl/portable/TimeService.cpp>
#include <scripting/src/ceres/portable/wsomain.cpp>
//#include <scripting/src/cloudos/portable/wsomain.cpp>
//#include <scripting/src/database/portable/filter.cpp>
//#include <scripting/src/database/portable/query.cpp>
//#include <scripting/src/database/portable/schema.cpp>
//#include <scripting/src/database/portable/wsomain.cpp>
//#include <scripting/src/file/portable/dir.cpp>
//#include <scripting/src/file/portable/ini.cpp>
//#include <scripting/src/file/portable/lnkfile.cpp>
//#include <scripting/src/file/portable/srchndx.cpp>
//#include <scripting/src/file/portable/vcs.cpp>
//#include <scripting/src/file/portable/wsomain.cpp>
//#include <scripting/src/file/portable/xar.cpp>
//#include <scripting/src/math/portable/const.cpp>
//#include <scripting/src/math/portable/function.cpp>
#include <scripting/src/math/portable/netwoni.cpp>
//#include <scripting/src/math/portable/poly.cpp>
#include <scripting/src/math/portable/sample.cpp>
//#include <scripting/src/math/portable/taylor.cpp>
#include <scripting/src/math/portable/wsomain.cpp>
#include <scripting/src/os/portable/Device.cpp>
#include <scripting/src/os/portable/DeviceManager.cpp>
#include <scripting/src/os/portable/Event.cpp>
//#include <scripting/src/os/portable/EventLog.cpp>
#include <scripting/src/os/portable/FileManager.cpp>
//#include <scripting/src/os/portable/Group.cpp>
//#include <scripting/src/os/portable/IoManager.cpp>
//#include <scripting/src/os/portable/Membership.cpp>
//#include <scripting/src/os/portable/NetworkManager.cpp>
#include <scripting/src/os/portable/ObjectManager.cpp>
#include <scripting/src/os/portable/ObjectName.cpp>
//#include <scripting/src/os/portable/PackageManager.cpp>
//#include <scripting/src/os/portable/PowerManager.cpp>
//#include <scripting/src/os/portable/Privileges.cpp>
#include <scripting/src/os/portable/Process.cpp>
#include <scripting/src/os/portable/ProcessManager.cpp>
#include <scripting/src/os/portable/Registry.cpp>
//#include <scripting/src/os/portable/Rights.cpp>
//#include <scripting/src/os/portable/SecurityManager.cpp>
#include <scripting/src/os/portable/ServiceBus.cpp>
//#include <scripting/src/os/portable/StorageManager.cpp>
#include <scripting/src/os/portable/Timer.cpp>
#include <scripting/src/os/portable/Topic.cpp>
#include <scripting/src/os/portable/Topics.cpp>
//#include <scripting/src/os/portable/User.cpp>
//#include <scripting/src/os/portable/wsomain.cpp>
//#include <scripting/src/security/portable/wsomain.cpp>
//#include <scripting/src/system/portable/bag.cpp>
//#include <scripting/src/system/portable/clist.cpp>
//#include <scripting/src/system/portable/dict.cpp>
#include <scripting/src/system/portable/fsm.cpp>
//#include <scripting/src/system/portable/graph.cpp>
#include <scripting/src/system/portable/list.cpp>
//#include <scripting/src/system/portable/map.cpp>
//#include <scripting/src/system/portable/multimap.cpp>
//#include <scripting/src/system/portable/network.cpp>
//#include <scripting/src/system/portable/ntable.cpp>
//#include <scripting/src/system/portable/queue.cpp>
//#include <scripting/src/system/portable/set.cpp>
//#include <scripting/src/system/portable/stack.cpp>
//#include <scripting/src/system/portable/string2.cpp>
#include <scripting/src/system/portable/sysfn.cpp>
//#include <scripting/src/system/portable/table.cpp>
//#include <scripting/src/system/portable/time.cpp>
//#include <scripting/src/system/portable/timeslot.cpp>
//#include <scripting/src/system/portable/tree.cpp>
//#include <scripting/src/system/portable/uuid.cpp>
#include <scripting/src/system/portable/wsomain.cpp>
#include <scripting/src/system/portable/xmlprsr.cpp>
//#include <scripting/src/vm/portable/Compiler.cpp>
//#include <scripting/src/vm/portable/wsomain.cpp>
// #include <scripting/src/web/portable/cfm.cpp>
// #include <scripting/src/web/portable/mail.cpp>
// #include <scripting/src/web/portable/mailmsg.cpp>
// #include <scripting/src/web/portable/pageinfo.cpp>
// #include <scripting/src/web/portable/pop3.cpp>
// #include <scripting/src/web/portable/rss.cpp>
// #include <scripting/src/web/portable/uddi.cpp>
// #include <scripting/src/web/portable/wiki.cpp>
// #include <scripting/src/web/portable/wscl.cpp>
// #include <scripting/src/web/portable/wsdl.cpp>
// #include <scripting/src/web/portable/wsomain.cpp>


#include <cos/src/cfs/portable/fcntlemu.cpp>
#include <cos/src/cfs/portable/stdioemu.cpp>
