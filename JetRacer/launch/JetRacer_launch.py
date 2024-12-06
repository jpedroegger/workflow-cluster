from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node (
            package='i2c_interface',
            node_executable='i2c_interface_node',
            node_name='i2c_interface'
        ),
        # Node (
        #     package='can_interface',
        #     namespace='jetracer',
        #     executable='can_interface_node',
        #     name='can_interface'
        # ),
        Node (
            package='oled_display',
            node_executable='oled_display_node',
            node_name='oled_display'
        ),
        Node (
            package='dc_motors',
            node_executable='dc_motors_node',
            node_name='dc_motors'
        ),
        Node (
            package='servo_motor',
            node_executable='servo_motor_node',
            node_name='servo_motor'
        ),
        Node (
            package='battery',
            node_executable='battery_node',
            node_name='battery'
        ),
    ])
