#ifndef TALKER_H__
#define TALKER_H__

// ROS2
#include <rclcpp/rclcpp.hpp>

// msgs
#include <std_msgs/msg/int64.hpp>

// Cpp and STL
#include <chrono>
#include <string>
#include <memory>
#include <functional>

namespace ros_learning
{
    class talker : public rclcpp::Node
    {
    public:
        talker();
        talker(const std::string &);
        ~talker();
        void run();
    private:
        size_t count_;
        rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr pub_;
    };


} // namespace ros_learning


#endif