
// OS: Data-structures (list,map,queue,graph,tree,trie)
#include <core/src/os/portable/contbase.cpp>
#include <core/src/os/portable/contmap.cpp>
#include <core/src/os/portable/conthash.cpp>
#include <core/src/os/portable/contnode.cpp>
#include <core/src/os/portable/contgrph.cpp>
#include <core/src/os/portable/contnet.cpp>
#include <core/src/os/portable/contpq.cpp>
#include <core/src/os/portable/conttree.cpp>
#include <core/src/os/portable/conttrie.cpp>

// OS: Operating system utility libraries
//#include <core/src/os/portable/cpu.cpp>
#include <core/src/os/portable/critsec.cpp>
//#include <core/src/os/portable/driver.cpp>
#include <core/src/os/portable/mutex.cpp>
//#include <core/src/os/portable/thread.cpp>
//#include <core/src/os/portable/tls.cpp>
#include <core/src/os/portable/winerror.cpp>
#include <core/src/os/portable/hashlock.cpp>
#include <core/src/os/portable/modulldr.cpp>

#include <external/include/os/arduino/fcntl.h>
#include <external/include/os/arduino/sys/stat.h>
#include <core/src/os/unix/pfile.cpp>

// Utils: Programming utility libraries
#include <core/include/utils/portable/stream/stream.x>
#include <core/src/utils/portable/memory/blob.cpp>
#include <core/src/utils/portable/stream/io.cpp>
#include <core/src/utils/portable/string/strproc.cpp>
#include <core/src/utils/portable/string/stralgo.cpp>
#include <core/src/utils/portable/string/atom.cpp>
#include <core/src/utils/portable/string/str.cpp>
#include <core/src/utils/portable/string/strlock.cpp>
#include <core/src/utils/portable/string/strlist.cpp>
#include <core/src/utils/portable/string/nvpair.cpp>
#include <core/src/utils/portable/string/regexpr.cpp>
#include <core/src/utils/portable/time/timeimp.cpp>
#include <core/src/utils/portable/csv/csv.cpp>
#include <core/src/utils/portable/any/any.cpp>
#include <core/src/utils/portable/any/anylist.cpp>
#include <core/src/utils/portable/any/anynvlst.cpp>
//#include <core/src/utils/portable/general/cell.cpp>
#include <core/src/utils/portable/general/crc.cpp>
#include <core/src/utils/portable/general/except.cpp>
//#include <core/src/utils/portable/general/table.cpp>
#include <core/src/utils/portable/general/tree.cpp>
#include <core/src/utils/portable/general/trilean.cpp>
#include <core/src/utils/portable/refcount/refcount.cpp>
//#include <core/src/utils/portable/asm/cppcall.cpp>
#include <core/src/utils/portable/asm/dyncall.cpp>
//#include <core/src/utils/portable/stream/stream.cpp>
#include <core/src/utils/portable/uuid/uuidimp.cpp>
#include <core/src/utils/portable/json/json.cpp>
#include <core/src/utils/portable/xml/minisax.cpp>
#include <core/src/utils/portable/xml/xmlprsr.cpp>
//#include <core/src/utils/portable/xml/xmlobj.cpp>
//#include <core/src/utils/portable/xml/xmllist.cpp>
//#include <core/src/utils/portable/xml/xmloprsr.cpp>
//#include <core/src/utils/portable/codec/pickle.cpp>

// FileIO: File management utilities
#include <core/src/fileio/portable/dirutil.cpp>
//#include <core/src/fileio/portable/fileimpl.cpp>
//#include <core/src/fileio/portable/ini.cpp>
#include <core/src/fileio/portable/pathfunc.cpp>
//#include <core/src/fileio/portable/urlfunc.cpp>
#include <core/src/fileio/unix/uxdirit.cpp>


#include <core/src/os/arduino/ardflash.cpp>
#include <core/src/os/arduino/ardsd.cpp>

// NetIO: Networking & communication libraries
#include <core/include/netio/portable/netsock.h>
#include <core/src/netio/arduino/ardsock.cpp>
//#include <core/src/netio/portable/memsock.cpp>
#include <core/src/netio/portable/netsock.cpp>
#include <core/src/netio/portable/tcpsock.cpp>
#include <core/src/netio/portable/nvtconn.cpp>
#include <system/src/inet/portable/inetproto.cpp>
#include <system/src/inet/portable/httpfile.cpp>
#include <system/src/inet/portable/httpimp.cpp>
//#include <system/src/inet/portable/xmlrpc.cpp>
//#include <system/src/inet/portable/smtpimp.cpp>
//#include <system/src/inet/portable/pop3imp.cpp>
//#include <system/src/inet/portable/ftpimp.cpp>

//#include <system/src/fs/portable/fsvfs.cpp>

//#include <system/src/futil/portable/archive.cpp>

#include <system/src/pobj/portable/pobjdyn.cpp>
#include <system/src/pobj/portable/pobjfact.cpp>
#include <system/src/pobj/portable/pobjimp.cpp>
#include <system/src/pobj/portable/pobjreq.cpp>

#include <system/src/sobj/portable/sobjbase.cpp>
#include <system/src/sobj/portable/lua_eng.cpp>
#include <system/src/sobj/portable/sobjapi.cpp>

//#include <system/src/sec/portable/acl.cpp>
//#include <system/src/sec/portable/uxsec.cpp>
//#include <system/src/sec/portable/md5rsa.cpp>
#include <system/src/sec/portable/secrand.cpp>

//#include <system/src/webul/portable/base64.cpp>
//#include <system/src/webul/portable/mime.cpp>
//#include <system/src/webul/portable/httppost.cpp>
//#include <system/src/webul/portable/httpprsr.cpp>

//#include <system/src/ws/portable/pobjidl.cpp>
//#include <system/src/ws/portable/pobjws.cpp>
//#include <system/src/ws/portable/pobjwsdl.cpp>
//#include <system/src/ws/portable/wmethod.cpp>

//#include <system/src/frame/portable/mqueue.cpp>
#include <system/src/frame/portable/logfile.cpp>
//#include <system/src/frame/portable/objcache.cpp>
//#include <system/src/frame/portable/thrdpool.cpp>
//#include <system/src/frame/portable/thrdplcy.cpp>


// TODO: Non-portable kernel libraries to port
#ifdef _WIN32
//#include <core/src/os/win32/Win32KernelObject.cpp>
//#include <core/src/os/win32/Win32CriticalSection.cpp>
//#include <core/src/os/win32/Win32CriticalSectionAdapter.cpp>
//#include <core/src/os/win32/Win32Mutex.cpp>
//#include <core/src/os/win32/Win32MutexAdapter.cpp>
//#include <core/src/os/win32/Win32Thread.cpp>
//#include <core/src/os/win32/Win32ThreadAdapter.cpp>
//#include <core/src/os/win32/Win32Process.cpp>
//#include <core/src/os/win32/Win32Process.cpp>
//#include <core/src/os/win32/Win32File.cpp>
//#include <core/src/fileio/win32/Win32DirIterator.cpp>
#endif

