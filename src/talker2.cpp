#include "ros2_learning/talker2.hpp"

namespace ros_learning
{
    talker::talker()
    : Node("talker_node")
    ,   count_(0)
    {
        pub_ = this->create_publisher<std_msgs::msg::Int64>("talker/channel", 1);

        timer_ = this->create_wall_timer(
            std::chrono::seconds (1),
            [this]()
            {
                this->run();
            }
        );
    }

    talker::talker(const std::string & node_name)
    :   Node(node_name)
    ,   count_(0)
    {
        pub_ = this->create_publisher<std_msgs::msg::Int64>("talker/channel", 1);

        timer_ = this->create_wall_timer(
            std::chrono::seconds (1),
            [this]()
            {
                this->run();
            }
        );
    }

    talker::~talker()
    {
    }

    void talker::run()
    {
        // Prepare msg
        auto msg = std_msgs::msg::Int64();
        msg.data = this->count_;

        pub_->publish(msg);
        ++count_;

        // Print in terminal
        RCLCPP_INFO(this->get_logger(), "I published %li", msg.data);
    }
} // namespace ros_learning