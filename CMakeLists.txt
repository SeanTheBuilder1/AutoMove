cmake_minimum_required(VERSION "3.0")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-O3 -std=c++17")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(CMAKE_CXX_COMPILER "g++")
aux_source_directory(./src/ SRC_LIST)

project("main")

# add_subdirectory(./lib/gcc_dll_release)

# set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")


set(EXECUTABLE_OUTPUT_PATH ./bin/)

# string(APPEND CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(
    main
    ${SRC_LIST}
    ${include_directories}
)


# target_include_directories(main PUBLIC ./include/ PUBLIC ./lib/gcc_dll_release/mswu PUBLIC ./src/)

# target_link_options(main PUBLIC -static-libgcc PUBLIC -static-libstdc++)
target_include_directories(main PUBLIC ./include/)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/libdatabase.a)



# target_link_libraries(main wxWidgets)




