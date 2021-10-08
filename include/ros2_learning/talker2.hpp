#ifndef TALKER2_H__
#define TALKER2_H__

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
    private:
        size_t count_;
        rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr pub_;
        rclcpp::TimerBase::SharedPtr timer_;
        void run();
    };


} // namespace ros_learning


#endif