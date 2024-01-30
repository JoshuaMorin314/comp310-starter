cmake_minimum_required(VERSION 3.5)

project(OperatingSystemsStarter)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

# Windows workaround (don't ask) 
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(hello)
add_subdirectory(hello-lib)
add_subdirectory(lwlog-lib)
add_subdirectory(lwlog-demo)
add_subdirectory(gtest-demo)
add_subdirectory(WU1dir)
add_subdirectory(WU2dir)
add_subdirectory(WU3dir)
add_subdirectory(WU4dir)
add_subdirectory(WU5dir)
add_subdirectory(WU6dir)
add_subdirectory(WU7dir)
add_subdirectory(WU8dir)
add_subdirectory(WU9dir)
add_subdirectory(WU10dir)

# You can use add_subdirectory() to add your own work. 
# Please don't remove the existing subdirectories.



