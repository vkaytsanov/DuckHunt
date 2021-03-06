project(DuckHunt)
# Set the cmake minimum version to 3.5.1
cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 14)


# Add all cpp source files under the src directory
file(GLOB SOURCES
        "src/core/audio/*.cpp"
        "src/core/audio/include/*.h"
        "src/core/data/*.cpp"
        "src/core/data/include/*.h"
        "src/core/graphics/*.cpp"
        "src/core/graphics/include/*.h"
        "src/core/graphics/screens/*.cpp"
        "src/core/graphics/screens/include/*.h"
        "src/core/graphics/windows/*.cpp"
        "src/core/graphics/windows/include/*.h"
        "src/core/logic/*.cpp"
        "src/core/logic/include/*.h"
        "src/core/logic/events/*.cpp"
        "src/core/logic/events/include/*.h"
        "src/core/logic/scripts/*.cpp"
        "src/core/logic/scripts/include/*.h"
        "src/desktop/desktop_launcher.cpp"
        "src/lib/*.cpp"
        "src/lib/include/*.h"
        "src/lib/utils/geometry/*.cpp"
        "src/lib/utils/geometry/include/*.h"
        "src/lib/utils/ui/*.cpp"
        "src/lib/utils/ui/include/*.h"
        "src/lib/utils/*.cpp"
        "src/lib/utils/include/*.h"
        "src/core/game_object/*.cpp"
        "src/core/game_object/include/*.h"
        "src/core/game_object/generic/*.cpp"
        "src/core/game_object/generic/include/*.h"
        "src/core/*.cpp"
        "src/core/include/*.h"
        )
add_executable(${PROJECT_NAME} ${SOURCES})

# in case CMake doesn't find the libraries
# change the following directory to your SDL2 folder with all the libraries
# and put the sdl2-config.cmake in the root of that folder. Don't forget to add the
# 32-bit .dll-s to the SysWOW64 folder
list(APPEND CMAKE_PREFIX_PATH "D:/SDL2")

find_package(sdl2 REQUIRED)
find_package(OpenGL REQUIRED)

message(STATUS "SDL2_INCLUDE_DIRS=${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2_LIBRARIES=${SDL2_LIBRARIES}")
message(STATUS "SDL2IMAGE_LIBRARIES=${SDL2IMAGE_LIBRARIES}")
message(STATUS "SDL2TTF_LIBRARIES=${SDL2TTF_LIBRARIES}")
message(STATUS "SDL2AUDIO_LIBRARIES=${SDL2AUDIO_LIBRARIES}")


include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2AUDIO_LIBRARIES} ${OPENGL_LIBRARIES})

