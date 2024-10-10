set(EXECUTABLE_NAME ImEarth)

file(GLOB_RECURSE IM_EARTH_SOURCES src/*.cpp)

if(MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
endif()

add_executable(${EXECUTABLE_NAME} ${IM_EARTH_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PRIVATE include)

target_link_libraries(${EXECUTABLE_NAME} glfw glad imgui glm stb_image)

target_precompile_headers(${EXECUTABLE_NAME} PRIVATE include/pch.h)