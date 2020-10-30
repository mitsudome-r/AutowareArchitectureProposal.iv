cmake_minimum_required(VERSION 3.0.2)
project(map_based_prediction)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wno-unused-parameter -Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_executable(map_based_prediction
  src/map_based_prediction_main.cpp
  src/map_based_prediction_ros.cpp
  src/map_based_prediction.cpp
)
target_include_directories(map_based_prediction
  ${EIGEN3_INCLUDE_DIR}
)

ament_auto_package(
  INSTALL_TO_SHARE
  launch
)