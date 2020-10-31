# CMakeList.txt : CMake project for 15_tag, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(resources "resources/calibri.ttf")
set(resources_bin_dir ${CMAKE_CURRENT_BINARY_DIR}/resources)

file(MAKE_DIRECTORY ${resources_bin_dir})
file(COPY ${resources} DESTINATION ${resources_bin_dir})
set(game_src "game/game.cpp" "game/game.h")
add_executable (15_tag "main.cpp" ${game_src})
set_target_properties (
	15_tag 
	PROPERTIES 
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON	
)
message("\r\n\r\n ahper=" ${PROJECT_SOURCE_DIR} "\r\n\r\n")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/"modules" ${CMAKE_MODULE_PATH})
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
if(NOT SFML_FOUND)
	message(SEND_ERROR "Failed to find sfml")
	return()
endif()

target_link_libraries(15_tag  sfml-graphics sfml-audio)
# TODO: Add tests and install targets if needed.
