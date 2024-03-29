#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace temp1_pkg
{
  class PubClass : public rclcpp::Node
  {
  public:
    PubClass(const std::string &node_name);
    virtual ~PubClass();

    void publish_msg(const std::string &msg);
    void run();

  private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr str_pub_;
    int count_;
  };
} // temp1_pkg
