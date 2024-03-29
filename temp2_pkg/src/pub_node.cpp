#include <rclcpp/executors.hpp>
#include <temp1_pkg/pub_lib.hpp>

int main (int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<temp1_pkg::PubClass>("temp2_pkg_node"));
  rclcpp::shutdown();

  return EXIT_SUCCESS;
}
