cmake_minimum_required(VERSION 3.10)
project(aml LANGUAGES CXX)

# --- Global Settings ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure binaries are built into a 'bin' folder in your build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# --- Find Dependencies ---
# These commands look for the -dev packages you installed via apt
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

# --- Define the Core Library ---
# We group all your engine/library files here so they only compile once
add_library(aml_core STATIC
    src/lib.cpp
    src/windowSrc/window.cpp
    src/windowSrc/styleManager.cpp
    src/shaderSrc/shaderResource.cpp
    src/shaderSrc/shaderProgram.cpp
    src/shaderSrc/uniform.cpp
    src/inputSrc/inputReciver.cpp
    src/shaderSrc/defaultShaders.cpp
    src/texture.cpp
    src/inputSrc/inputCallbacks.cpp
    # Note: .ipp files are usually included in headers and don't need to be here,
    # but keeping it won't hurt if it's strictly required by your setup.
    src/vectorResource.ipp
)

# --- Header Management ---
# This tells the compiler where to look for your .hpp files
target_include_directories(aml_core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- Link Libraries ---
# Linking these to 'aml_core' means any executable using aml_core 
# will automatically know how to find OpenGL, GLEW, and GLM.
target_link_libraries(aml_core PUBLIC 
    OpenGL::GL
    GLEW::GLEW
    glm::glm
    glfw        # Using the system name for glfw
    glut        # Using the system name for glut
)

# --- Executables (Tests) ---
# Link your test files to the aml_core library we defined above

add_executable(3dTest test/3dTest.cpp)
target_link_libraries(3dTest PRIVATE aml_core)

add_executable(TextureTest test/TextureTest.cpp)
target_link_libraries(TextureTest PRIVATE aml_core)

add_executable(SSBOTest test/ssboTest.cpp)
target_link_libraries(SSBOTest PRIVATE aml_core)