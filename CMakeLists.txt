cmake_minimum_required(VERSION 3.10)

# set the project name
project(aml)


# add the executable
set(CMAKE_CXX_STANDARD 17)
set(SOURCE
   ${SOURCE}
   
   ${CMAKE_CURRENT_SOURCE_DIR}/file2.cpp
   PARENT_SCOPE
)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/test)
link_libraries("glfw" "GL" "GLEW" "glut")
add_executable(test 
    ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderResource.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderProgram.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/uniform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vectorResource.ipp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/inputReciver.cpp
    )