#include "ros2_learning/listener.hpp"

constexpr auto ROS2NODENAME = "listener_node";

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ros_learning::listener>(ROS2NODENAME));
    rclcpp::shutdown();
    return 0;
}

