# CMakeList.txt : CMake project for 15_tag, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(resources "resources/calibri.ttf")
set(resources_bin_dir ${CMAKE_CURRENT_BINARY_DIR}/resources)

file(MAKE_DIRECTORY ${resources_bin_dir})
file(COPY ${resources} DESTINATION ${resources_bin_dir})
set(assets_src      "assets/assets.h")
set(game_model_src  "game_model/game_model.h" "game_model/game_model.cpp")
set(game_render_src "game_render/game_render.h" "game_render/game_render.cpp")     
set(game_controller_src "game_controller/game_controller.h" "game_controller/game_controller.cpp")


add_executable (15_tag "main.cpp" ${assets_src}  ${game_model_src}  ${game_render_src} ${game_controller_src})
set_target_properties (
	15_tag 
	PROPERTIES 
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON	
)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/"modules" ${CMAKE_MODULE_PATH})
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
if(NOT SFML_FOUND)
	message(SEND_ERROR "Failed to find sfml")
	return()
endif()

target_link_libraries(15_tag  sfml-graphics sfml-audio)
