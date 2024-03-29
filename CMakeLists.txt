cmake_minimum_required(VERSION 3.5)
project(ros2_learning)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
)

# Example 1, talker
add_executable(talker
  src/talker_node.cpp
  src/talker.cpp
)
ament_target_dependencies(talker rclcpp std_msgs)

install(TARGETS
  talker
  DESTINATION lib/${PROJECT_NAME}
)

# Example 2, talker
add_executable(talker2
  src/talker2_node.cpp
  src/talker2.cpp
)
ament_target_dependencies(talker2 rclcpp std_msgs)

install(TARGETS
  talker2
  DESTINATION lib/${PROJECT_NAME}
)

# Example 3, listener
add_executable(listener
  src/listener_node.cpp
  src/listener.cpp
)
ament_target_dependencies(listener rclcpp std_msgs)

install(TARGETS
  listener
  DESTINATION lib/${PROJECT_NAME}
)

# Example 4, listener
add_executable(timer_examples
  src/timer_examples.cpp
)
ament_target_dependencies(timer_examples rclcpp std_msgs)

install(TARGETS
  timer_examples
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
