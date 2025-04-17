cmake_minimum_required(VERSION 3.8)
project(cruise_control VERSION 0.1.0 LANGUAGES CXX)

# Enable C++17 (or a higher version)
set(CMAKE_CXX_STANDARD 17)

find_package(Matplot++ QUIET)
if(NOT Matplot++_FOUND)
  # FetchContent to download matplotplusplus
  include(FetchContent)

  # Fetch matplotlibcpp library
  FetchContent_Declare(
    matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
    GIT_TAG origin/master)
    FetchContent_GetProperties(matplotplusplus)

  if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
  endif()

  FetchContent_MakeAvailable(matplotplusplus)
endif()

# Source files
file(GLOB SOURCES "src/*.cpp")

# We can build cruise_control by building all cpp scripts
add_executable(cruise_control ${SOURCES})

target_compile_features(cruise_control PUBLIC cxx_std_17)
set (CMAKE_CXX_FLAGS "-O3")

# Link against matplotlibcpp and Python libraries
target_link_libraries(cruise_control PUBLIC Matplot++::matplot)
