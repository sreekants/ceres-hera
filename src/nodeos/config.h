



// Empact build specific configurations
#define _ARDUINO
#define _CERES
#define NDEBUG
#define USE_MEM_STREAM
#define USE_MINISAX
#define SOBJ_USE_LUA
#define SOBJ_LINK_LUA
#define EXPORT_C
#define UTILS_EMPACT_EOF	__ceres_eof

int tprintf( const char* pszFormat, ... );


#define ASSERT(exp) (NULL)
#define VERIFY(exp) (exp)

#ifndef NDEBUG
#define TRACE	 	::tprintf
#else /* NDEBUG */ 
#define TRACE	 	(1)? NULL : ::tprintf
#endif /* NDEBUG */ 

