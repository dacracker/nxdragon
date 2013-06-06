# Helper function for creating consistent filters
# in Visual Studio. 

set(NX_SOURCE_GROUP "source")

function(nx_filter files)
	
	set(source_list )
	foreach(file ${files})

		if(IS_ABSOLUTE ${file})
			set(source_list ${source_list} ${file})
		else()
			set(source_list ${source_list} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
		endif()

	endforeach()

	source_group(${NX_SOURCE_GROUP} FILES ${source_list})
	
endfunction()
