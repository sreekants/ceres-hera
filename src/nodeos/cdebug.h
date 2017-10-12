
#ifdef _ARDUINO
int tprintf( const char* pszFormat, ... )
{
  char szBuffer[1024];
  va_list arglist;

  va_start( arglist, pszFormat );
  vsnprintf( szBuffer, 1024, pszFormat, arglist );

  Serial.print( szBuffer );

  va_end( arglist );

  return 0;
}

void debug_print_boot_fs()
{
  tprintf( "Boot file system listing:\n" );
  fs::Dir dir = SPIFFS.openDir("/");
  while (dir.next()) {
      fs::File f = dir.openFile("r");
      tprintf( "%s (size %i bytes)\n", dir.fileName().c_str(), f.size() );
  }  
}
#endif

