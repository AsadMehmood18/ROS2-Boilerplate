#include "rclcpp/rclcpp.hpp"
#include "<your_package_name>/srv/<your_service_name>.hpp"   // Replace with your package and service

// Alias for convenience
typedef <your_package_name>::srv::<YourServiceName> ServiceType;

class ServiceNode : public rclcpp::Node
{
public:
  ServiceNode() : Node("service_node")
  {
    service_server_ = this->create_service<ServiceType>(
      "service_name",   // <-- Replace with your service name (topic name)
      std::bind(&ServiceNode::handle_request, this,
                std::placeholders::_1, std::placeholders::_2)
    );
    RCLCPP_INFO(this->get_logger(), "Service server ready: %s", "service_name");
  }

private:
  void handle_request(
    const ServiceType::Request::SharedPtr request,
    ServiceType::Response::SharedPtr response)
  {
    // TODO: Implement your service logic here
    (void)request;   // Avoid unused variable warnings (remove once implemented)
    (void)response;
    RCLCPP_INFO(this->get_logger(), "Service request received");
  }

  rclcpp::Service<ServiceType>::SharedPtr service_server_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ServiceNode>());
  rclcpp::shutdown();
  return 0;
}
