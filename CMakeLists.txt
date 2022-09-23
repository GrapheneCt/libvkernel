cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{MEPSDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{MEPSDK}/share/mep.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define MEPSDK to point to your SDK path!")
  endif()
endif()

project(libvkernel C)

add_definitions(-mtiny=0 -mabsdiff -maverage -mbitops -mclip -mdiv -mleadz -mminmax -mmult -mrepeat -msatur -mvl64 -mvliw -mcop64 -D__MEP_CONFIG_CP_DATA_BUS_WIDTH=64 -mivc2 -O3 -std=c99 -nostdlib)

set( VKERNEL_SOURCES
     src/memory.c
     src/system.c
	 src/vthread.c
	 src/mempool.c
)

set( VKERNEL_HEADERS
     include/vnz/common.h
	 include/vnz/debug.h
	 include/vnz/errno.h
	 include/vnz/memory.h
     include/vnz/system.h
	 include/vnz/vthread.h
	 include/vnz/mempool.h
)

include_directories(include)

add_library(${PROJECT_NAME}_objs OBJECT 
	${VKERNEL_SOURCES}
)

add_library(vkernel $<TARGET_OBJECTS:${PROJECT_NAME}_objs>)

install(FILES
	${VKERNEL_HEADERS}
	DESTINATION include/vnz
)

install(TARGETS vkernel
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
