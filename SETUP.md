# ROS 2 Package Setup Guide

This guide provides instructions for setting up and creating a **ROS 2 package** on Ubuntu/Linux using the ROS 2 Humble distribution.

---

## 1. Install ROS 2 Humble

Follow the official ROS 2 Humble installation guide for Ubuntu:

* [ROS 2 Humble Installation (General)](https://docs.ros.org/en/humble/Installation.html)
* [ROS 2 Humble Installation on Ubuntu (Deb Packages)](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html)

Make sure to source the setup file after installation:

```bash
source /opt/ros/humble/setup.bash
```

You can add this line to your `~/.bashrc` to source it automatically:

```bash
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

---

## 2. Create a Workspace

Create a workspace directory and a `src` folder inside it:

```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws
```

---

## 3. Create a Package

Use the following command to create a new ROS 2 package:

```bash
ros2 pkg create <package_name> --build-type ament_cmake --dependencies rclcpp std_msgs
```

Replace `<package_name>` with the name of your package.

Example:

```bash
ros2 pkg create my_robot_pkg --build-type ament_cmake --dependencies rclcpp std_msgs
```

---

## 4. Build the Package

Navigate to the root of the workspace and build:

```bash
cd ~/ros2_ws
colcon build --symlink-install
```

Source the local setup file:

```bash
source install/setup.bash
```

---

## 5. Run the Package

You can now run your package nodes using:

```bash
ros2 run <package_name> <node_executable>
```

---

## 6. Helpful Tips

* Always source the correct setup file before running commands:

  * ROS 2 setup: `source /opt/ros/humble/setup.bash`
  * Workspace setup: `source ~/ros2_ws/install/setup.bash`
* Use `colcon clean` (with `colcon-clean` plugin) if you encounter build issues.
* You can check available nodes with:

```bash
ros2 node list
```


