# CMakeList.txt : CMake project for 15_tag, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (15_tag "main.cpp")
set_target_properties (
	15_tag 
	PROPERTIES 
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON	
)


#set(ENV{SFML_DIR} "c:/libs/sfml/x64")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/"modules/" ${CMAKE_MODULE_PATH})
#message("\r\nLOOH\r\n" ${PROJECT_SOURCE_DIR})
#message("\r\n\r\n" ${SFML_INCLUDE_DIR})
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
if(NOT SFML_FOUND)
	message(SEND_ERROR "Failed to find sfml")
	return()
endif()
#
# if(WIN32)
#    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} -lmingw32 -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid)
#else()
#    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES}  )
#endif()

#message("\r\n\r\n" ${SFML_INCLUDE_DIR})
#message("\r\n\r\n" ${SFML_LIBRARIES})
#message("\r\n\r\n" ${SFML_DEPENDENCIES})

#target_include_directories(15_tag PRIVATE  ${SFML_INCLUDE_DIR})
target_link_libraries(15_tag  sfml-graphics sfml-audio)
# TODO: Add tests and install targets if needed.
