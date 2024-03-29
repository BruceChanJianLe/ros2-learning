#include "temp1_pkg/pub_lib.hpp"
#include <std_msgs/msg/detail/string__struct.hpp>

namespace temp1_pkg
{
  PubClass::PubClass(const std::string &node_name)
    : rclcpp::Node(node_name)
      , count_{0}
  {
    str_pub_ = this->create_publisher<std_msgs::msg::String>("~/msg", 1);
    run();
  }

  PubClass::~PubClass()
  {
  }

  void PubClass::publish_msg(const std::string &msg)
  {
    std_msgs::msg::String str_msg;
    str_msg.data = msg + std::to_string(count_);

    RCLCPP_INFO_STREAM(get_logger(), "I have spoken: " << str_msg.data);
    str_pub_->publish(str_msg);
    ++count_;
  }

  void PubClass::run()
  {
    rclcpp::WallRate r(1);

    while(rclcpp::ok())
    {
      publish_msg({"I have spoken"});
      r.sleep();
    }
  }
} // temp1_pkg
