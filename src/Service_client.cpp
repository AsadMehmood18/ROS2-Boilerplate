#include "rclcpp/rclcpp.hpp"
#include "<your_package_name>/srv/<your_service_name>.hpp"   // Replace with your package and service
#include <iostream>

// Alias for convenience
typedef <your_package_name>::srv::<YourServiceName> ServiceType;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  // Create node
  auto node = rclcpp::Node::make_shared("service_client_node");

  // Create client
  auto client = node->create_client<ServiceType>("service_name"); // <-- Replace with your service name

  // Create request
  auto request = std::make_shared<ServiceType::Request>();
  // TODO: Fill in request fields here
  // request->field_name = value;

  // Wait for service availability
  client->wait_for_service();

  // Send request asynchronously
  auto result_future = client->async_send_request(request);

  // Spin until result is received
  if (rclcpp::spin_until_future_complete(node, result_future) ==
      rclcpp::FutureReturnCode::SUCCESS)
  {
    auto response = result_future.get();
    // TODO: Handle response logic here
    // e.g., std::cout << "Response: " << response->field_name << std::endl;
  }
  else
  {
    std::cerr << "Failed to call service" << std::endl;
  }

  rclcpp::shutdown();
  return 0;
}
