#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"   // Replace with your message type

#include <iostream>

class SubscriberNode : public rclcpp::Node
{
public:
  SubscriberNode() : Node("subscriber_node")
  {
    // Create subscription
    subscription_ = this->create_subscription<std_msgs::msg::String>(   // <-- Replace with your message type
      "topic_name",    // <-- Replace with your topic name
      10,              // QoS (queue size)
      std::bind(&SubscriberNode::callback, this, std::placeholders::_1)
    );
  }

private:
  void callback(const std_msgs::msg::String & msg) const   // <-- Replace type if using custom message
  {
    // TODO: Implement logic to handle received message
    // Example:
    // std::cout << "Received: " << msg.data << std::endl;
    // RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SubscriberNode>());
  rclcpp::shutdown();
  return 0;
}
