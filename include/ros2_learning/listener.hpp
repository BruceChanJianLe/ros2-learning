#ifndef LISTENER_H__
#define LISTENER_H__

// ROS2 
#include <rclcpp/rclcpp.hpp>

// msgs
#include <std_msgs/msg/int64.hpp>

// CPP and STL
#include <chrono>
#include <string>
#include <memory>
#include <functional>

namespace ros_learning
{
    class listener : public rclcpp::Node
    {
    public:
        listener(const std::string &);
        ~listener();
    private:
        rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr sub_;
        void subCallback(const std_msgs::msg::Int64::SharedPtr) const;
    };
} // namespace ros_learning


#endif