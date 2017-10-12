
#if defined (_UNIX) || defined(__MINGW32__)|| defined(_WIN32)
#include <cos/include/kernl/portable/Ceres.h>
#include <cos/include/cvm/portable/ApplicationHost.h>
#else

#define CERES_NODE      // Ceres node specific build.
#define FS_NO_GLOBALS

#include <SoftwareSerial.h>
#include <FS.h>
#include <SD.h>
#include <Esp.h>
#include <ESP8266WiFi.h>

#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include "stdclib.h"
#include "config.h"
#include "luaport.h"
#include "ported.h"
#include "ceres.node.h"
#include "cdebug.h"
#endif

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
#define CAYENNE_USERNAME  "3f9a2d60-a9ab-11e7-a1da-536ee79fd847"
#define CAYENNE_PASSWORD  "3da89817169700941c13d74206ea9a25d4a302ee"
#define CAYENNE_CLIENTID  "a4c24d70-a9ed-11e7-b0e9-e9adcff3788e"

#ifdef _ARDUINO
#define CERES_ENABLE_CAYENNE
#endif

#define CERES_DEFAULT_WIFI_SSID       "kalyan"
#define CERES_DEFAULT_WIFI_PASSWORD   "pa55word123"
#define CERES_CLOUD_FILE_SERVER       "farmhub.hamarabazaar.org"

#define CERES_MODULE_EXPORT_MAP_ENTRY(mod)    { #mod, (PFN_KMODULE_MODULEMAIN) &mod##ModuleMain }

using namespace Ceres;

void init_vfs_config( OS_INIT_INFO& init_info )
{
	MOUNT_POINT mp, mp_web;

	TCHAR szCloudFSConfig[MAX_STR];
	sprintf( szCloudFSConfig, "/ceres/download/images/%i_%i^host=%s", CERES_VERSION_MAJOR, 
		CERES_VERSION_MINOR, 
		CERES_CLOUD_FILE_SERVER );
  
	ktrace( EVENTLOG_ERROR_TYPE, "init file system.\n" );

	CFileSystemManager& fm	= CFileSystemManager::instance();

	if( !fm.GetBootFileSystem("/", &mp) )
		throw_system_exception( E_UNEXPECTED );

	if( !fm.GetCloudFileSystem(szCloudFSConfig, &mp_web) )
		throw_invalid_arg( szCloudFSConfig );

	// Initialize the operating system boot configuration
	memset( &init_info, 0, sizeof(OS_INIT_INFO) );
	init_info.m_hFileSystem   = mp.hVFS;
	init_info.m_pFileSystem   = mp.pVtbl;
	init_info.m_hCloudFileSystem  = mp_web.hVFS;
	init_info.m_pCloudFileSystem  = mp_web.pVtbl;
}

void InitializeHostOS()
{
#ifdef _ARDUINO
  // Initialize serial port for logging.
  Serial.begin( 115200 );
  while (!Serial)
    delay( 50 );


  Serial.print( "Initializing ESP modules (Wifi,SPIFF)." );
  WiFi.begin( CERES_DEFAULT_WIFI_SSID, CERES_DEFAULT_WIFI_PASSWORD );

  while (WiFi.status() != WL_CONNECTED) {
    delay( 500 );
    Serial.print( "." );
  }

  SPIFFS.begin();

  yield();
  Serial.println( "done." );
#endif //_ARDUINO
}

void InitOS()
{
#ifdef _ARDUINO
  // Setup the kernel logger to print output to serial port.
	XLogger::set_logger( __gKernelLogger );
#endif

	kprintf( EVENTLOG_SUCCESS, "OS booting up.\n" );

	___TRY
	{

		//client.close();
			OS_INIT_INFO  init_info;
			memset( &init_info, 0, sizeof( OS_INIT_INFO ) );

			// Use the flash boot mode
			init_info.m_dwFlags = OS_INIT_FLAG_FLASH_BOOT;

			init_vfs_config( init_info );

#ifdef _ARDUINO
		// Register all DSO objects to the NULL DSO loader on 
		// Arduino knows of the export tables.

		static OS_MODULE_DISPATCH_MAP CeresModuleExports[] =
		{
			CERES_MODULE_EXPORT_MAP_ENTRY( COM ),
			CERES_MODULE_EXPORT_MAP_ENTRY( CDVM ),
			CERES_MODULE_EXPORT_MAP_ENTRY( CFS ),
			CERES_MODULE_EXPORT_MAP_ENTRY( CERES ),
			//CERES_MODULE_EXPORT_MAP_ENTRY(CLOUDOS),
			//CERES_MODULE_EXPORT_MAP_ENTRY(FILE),
			CERES_MODULE_EXPORT_MAP_ENTRY( MATH ),
			CERES_MODULE_EXPORT_MAP_ENTRY( SYSTEM ),
			//CERES_MODULE_EXPORT_MAP_ENTRY(VM)

			// Last module in the set should be the application host.
			CERES_MODULE_EXPORT_MAP_ENTRY(CAH)
		};

		OperatingSystem::RegisterModules( CeresModuleExports, itemsof( CeresModuleExports ) );
#endif

		OperatingSystem::Initialize( &init_info );

	}
		___CATCH( std_exception, e )
	{
		kprintf( EVENTLOG_ERROR_TYPE, "[%s].\n", e.what() );
		return;
	}
	___END_CATCH
	kprintf( EVENTLOG_SUCCESS, "OS ready.\n" );
}

/*
void Test()
{
    TRACE( "Here!\n" );
    CApplicationHost host;
    CApplicationConfigParser  parser( host );
    memstream_parse_file( parser, KERNL_SOFTWARE_FILE );
}
*/

void setup()
{
  // Initialize the host operating system and its facilities
  InitializeHostOS();

  // Initalize the operating system
	InitOS();
	//Test();
 
#ifdef CERES_ENABLE_CAYENNE
  // Intialize could communication facilities.  
  // TODO: Move this to the network manager.
  kprintf( EVENTLOG_SUCCESS, "Initializing Cayenne." );
	Cayenne.begin( CAYENNE_USERNAME, CAYENNE_PASSWORD, CAYENNE_CLIENTID );
#endif

#ifdef _ARDUINO
	debug_print_boot_fs();
#endif
}

void loop()
{
  /*
  ___TRY
  {
	  //OperatingSystem::Loop(100, NULL);
  }
  ___CATCH( std_exception, e )
  {
    kprintf( EVENTLOG_ERROR_TYPE, "[%s].\n", e.what() );
    return;
  }
  ___END_CATCH
  */
#ifdef CERES_ENABLE_CAYENNE
	Cayenne.loop();
#endif
}



#ifdef CERES_ENABLE_CAYENNE
//Default function for processing actuator commands from the Cayenne Dashboard.
CAYENNE_IN_DEFAULT()
{
	CDeviceManager::instance().PostVirtualPinMessage( request.channel, getValue.getId(), getValue.asString()  );
}
#endif 

