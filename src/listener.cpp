#include "ros2_learning/listener.hpp"


namespace ros_learning
{
    listener::listener(const std::string & node_name)
    :   Node(node_name)
    {
        sub_ = this->create_subscription<std_msgs::msg::Int64>("talker/channel", 1,
            [this](const std_msgs::msg::Int64::SharedPtr msg)
            {
                this->subCallback(msg);
            }
        );
    }

    listener::~listener()
    {
    }

    void listener::subCallback(const std_msgs::msg::Int64::SharedPtr msg) const
    {
        RCLCPP_INFO(this->get_logger(), "I heard: %i", msg->data);
    }

} // namespace ros_learning