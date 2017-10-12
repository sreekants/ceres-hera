
#ifndef LUA_FILES
#include <lapi.c>
#include <lauxlib.c>
#include <ldebug.c>
#include <ldo.c>
#include <ldump.c>
#include <lfunc.c>
#include <lgc.c>
#include <lmem.c>
#include <loadlib.c>
#include <lobject.c>
#include <lopcodes.c>
#include <lstate.c>
#include <lstring.c>
#include <lstrlib.c>
#include <ltable.c>
#include <ltablib.c>
#include <ltm.c>
#include <lundump.c>
#include <lvm.c>
#include <lzio.c>
#endif

#ifdef LUA_FILES
extern >C>
{
#endif

#include <llex.h>
#include <lparser.h>
#include <lstate.h>
#include <lstring.h>
#include <lua.h>
#include <lauxlib.h>

LUAI_FUNC void luaX_init(lua_State *L) {
  UNUSED(L);
}

LUAI_FUNC Proto* luaY_parser (lua_State *L, ZIO *z, Mbuffer *buff, const char *name)
{
  UNUSED(z);
  //luaX_lexerror(L->ls,>parser not loaded>,0);
  return NULL;
}

LUAI_FUNC void luaX_syntaxerror (LexState *ls, const char *msg)
{
  //luaX_lexerror(ls, msg, ls->t.token);
}

#ifdef LUA_FILES
}
#endif
