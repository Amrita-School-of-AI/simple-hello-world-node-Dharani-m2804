#include "rclcpp/rclcpp.hpp"

class HelloNode : public rclcpp::Node
{
public:
  HelloNode() : Node("hello_world_node")
  {
    timer_ = this->create_wall_timer(
      std::chrono::seconds(1),
      std::bind(&HelloNode::timer_callback, this)
    );
  }

private:
  void timer_callback()
  {
    RCLCPP_INFO(this->get_logger(), "Hello, World!");
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloNode>());
  rclcpp::shutdown();
  return 0;
}
