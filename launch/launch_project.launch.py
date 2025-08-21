from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        # Example Node 1
        Node(
            package='<your_package_name>',        # Replace with your package
            executable='<your_executable>',       # Replace with your executable
            name='<your_node_name>',              # Optional: custom node name
            parameters=[
                {'<param_name>': <param_value>}   # Replace with your parameters
            ],
            output='screen'                       # Show logs in terminal
        ),

        # Example Node 2
        Node(
            package='<your_package_name>',
            executable='<another_executable>',
            name='<another_node_name>',
            parameters=[
                {'<param_name>': <param_value>}
            ],
            output='screen'
        ),

        # Example: Run a shell command (optional)
        ExecuteProcess(
            cmd=['ros2', 'topic', 'echo', '/<topic_name>'],   # Replace with your topic
            output='screen'
        )
    ])
