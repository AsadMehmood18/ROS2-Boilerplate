#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"   // Replace with your message type

#include <chrono>
#include <functional>

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node
{
public:
  PublisherNode() : Node("publisher_node")
  {
    // Create publisher
    publisher_ = this->create_publisher<std_msgs::msg::String>(   // <-- Replace with your message type
      "topic_name",   // <-- Replace with your topic name
      10              // QoS (queue size)
    );

    // Create timer for periodic publishing
    timer_ = this->create_wall_timer(
      1s,   // <-- Replace with your desired interval
      std::bind(&PublisherNode::publish_message, this)
    );
  }

private:
  void publish_message()
  {
    // TODO: Create and fill your message here
    auto message = std_msgs::msg::String();
    // message.data = "Your data here";

    // TODO: Add logging if needed
    // RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());

    // Publish message
    publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PublisherNode>());
  rclcpp::shutdown();
  return 0;
}
