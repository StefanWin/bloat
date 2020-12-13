cmake_minimum_required(VERSION 3.6)
project(bloat)

set(CMAKE_CXX_STANDARD 17)

set(APP_TARGET bloat)

find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_sources 
    "${PROJECT_SOURCE_DIR}/include/core/*.h"
    "${PROJECT_SOURCE_DIR}/include/util/*.h"
    "${PROJECT_SOURCE_DIR}/include/renderer/*.h"
    "${PROJECT_SOURCE_DIR}/src/core/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/util/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/renderer/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${APP_TARGET} ${all_sources})

target_link_libraries(
        ${APP_TARGET}
        glfw
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${EXTRA_LIBS}
)