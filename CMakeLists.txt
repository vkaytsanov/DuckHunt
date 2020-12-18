project(DuckHunt)
# Set the cmake minimum version to 3.5.1
cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 14)


# Add all cpp source files under the src directory
file(GLOB SOURCES
        "src/core/data/*.cpp"
        "src/core/data/include/*.h"
        "src/core/graphics/*.cpp"
        "src/core/graphics/include/*.h"
        "src/core/logic/*.cpp"
        "src/core/logic/include/*.h"
        "src/desktop/desktop_launcher.cpp"
        "src/utils/*.cpp"
        "src/utils/include/*.h"
        "src/core/game_object/*.cpp"
        "src/core/game_object/include/*.h"
        "src/core/*.cpp"
        "src/core/include/*.h"
        )
add_executable(${PROJECT_NAME} ${SOURCES})

set(SDL2_INCLUDE_DIR D:/SDL2/include)
set(SDL2_LIB_DIR D:/SDL2/lib)


include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})
find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})