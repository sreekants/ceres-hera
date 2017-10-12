typedef struct lua_State lua_State;
typedef struct luaL_Reg;
typedef double lua_Number;
typedef int lua_Integer;
typedef int( *lua_CFunction ) (lua_State *L);
typedef struct lua_Debug lua_Debug;  /* activation record */
typedef const char * (*lua_Reader) (lua_State *L, void *ud, size_t *sz);
typedef int( *lua_Writer ) (lua_State *L, const void* p, size_t sz, void* ud);


int __ceres_eof( FILE * );

#undef panic

// Lua definitions
#define LUA_CORE
#define LUAI_THROW(L,c)	___THROW(c)
#define LUAI_TRY(L,c,a)	___TRY { a } ___CATCH(std_exception,ex){}__ENDCATCH \
	{ if ((c)->status == 0) (c)->status = -1; }
#define luai_jmpbuf	int  /* dummy variable */

#define strcoll strcmp
