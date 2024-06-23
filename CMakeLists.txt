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
set (DCMAKE_EXE_LINKER_FLAGS "-fuse-ld=mold")
set (DCMAKE_SHARED_LINKER_FLAGS "-fuse-ld=mold")

link_libraries("glfw" "GL" "GLEW" "glut")

add_executable(3dTest 
    ${CMAKE_CURRENT_SOURCE_DIR}/test/3dTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/windowSrc/window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/windowSrc/styleManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderSrc/shaderResource.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderSrc/shaderProgram.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderSrc/uniform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vectorResource.ipp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/inputSrc/inputReciver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderSrc/defaultShaders.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/inputSrc/inputCallbacks.cpp
    )

add_executable(TextureTest 
    ${CMAKE_CURRENT_SOURCE_DIR}/test/TextureTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lib.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/windowSrc/window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/windowSrc/styleManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderSrc/shaderResource.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderSrc/shaderProgram.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderSrc/uniform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vectorResource.ipp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/inputSrc/inputReciver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shaderSrc/defaultShaders.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/texture.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/inputSrc/inputCallbacks.cpp
    )
