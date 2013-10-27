

include_directories(${LUA_INCLUDE_DIR} 
					../../src)

set(nxlua_inc 
	nx_def.h
	nx_doc.h
	nx_init.h
	nx_lua.h
	# NxKernel
	nx_lua_list.h)

set(nxlua_src 
	nx_init.c
	nx_lua.c
	# NxKernel
	nx_lua_list.c) 

add_library(nxlua SHARED ${nxlua_src} ${nxlua_inc})

target_link_libraries(nxlua nxkernel)
target_link_libraries(nxlua debug ${LUA_DEBUG_LIBRARY} optimized ${LUA_LIBRARY})

set_target_properties(nxlua PROPERTIES 
					  		DEFINE_SYMBOL NXDRAGON_BUILD_LUA)

nx_filter("${nxlua_src};${nxlua_inc}")
