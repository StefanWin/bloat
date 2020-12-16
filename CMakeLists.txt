cmake_minimum_required(VERSION 3.6)
project(bloat)

set(CMAKE_CXX_STANDARD 17)

set(APP_TARGET bloat)

if(UNIX)
    set(OpenGL_GL_PREFERENCE GLVND)
endif()

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

add_subdirectory(external/glfw)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

add_subdirectory(external/glm)
include_directories(${GLM_INCLUDE_DIRS})

include_directories(
    ${PROJECT_SOURCE_DIR}/include/ # not specifically adding directories preserves directory structure
    ${PROJECT_SOURCE_DIR}/include/imgui # otherwise it wont find itself in the subdirectories
    ${PROJECT_SOURCE_DIR}/external/stb
)

file(GLOB all_sources 
    "${PROJECT_SOURCE_DIR}/src/core/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/util/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/renderer/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/imgui/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(${APP_TARGET} ${all_sources})

target_link_libraries(
        ${APP_TARGET}
        glfw
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
)