#include "ros2_learning/talker2.hpp"

constexpr auto ROS2NODENAME = "talker2_node";

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ros_learning::talker>(ROS2NODENAME));
    rclcpp::shutdown();

    return 0;
}