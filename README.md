# ROS2 Boilerplate

This repository provides a simple **ROS2 boilerplate project** to quickly get started with ROS2 development. It includes configurations for building, debugging, and running ROS2 nodes, along with example source files for common ROS2 communication patterns.

---

## 📂 Project Structure

```
ROS2-Boilerplate/
├── .vscode/
│   ├── launch.json        # Debug configuration
│   ├── tasks.json         # Build and debug tasks
│
├── launch/
│   ├── launch_project.launch.py  # Launch file to start nodes
│
├── src/
│   ├── Client.cpp         # Example client node
│   ├── Publisher.cpp      # Example publisher node
│   ├── Service.cpp        # Example service node
│   ├── Subscriber.cpp     # Example subscriber node
```

---

## ⚙️ Setup Instructions

1. **Clone the Repository**

   ```bash
   git clone <your_repo_url>
   cd ROS2-Boilerplate
   ```

2. **Build the Workspace**

   ```bash
   source /opt/ros/humble/setup.bash
   colcon build --symlink-install
   ```

3. **Source the Workspace**

   ```bash
   source install/setup.bash
   ```

---

## 🚀 Running Nodes

You can run nodes individually:

```bash
ros2 run <package_name> <node_executable>
```

Or use the provided launch file:

```bash
ros2 launch launch_project.launch.py
```

---

## 🐛 Debugging

This project includes **VS Code debug configurations**:

* `tasks.json`: Build & Debug tasks
* `launch.json`: Configures debugging with `gdbserver`

### Example Debugging Steps:

1. Start build with debug symbols:

   ```bash
   colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo
   ```
2. Run node with `gdbserver`:

   ```bash
   ros2 run --prefix 'gdbserver localhost:3000' <package_name> <node_executable>
   ```
3. Launch the VS Code debugger.

---

## 📌 Notes

* Modify `.vscode/launch.json` and `.vscode/tasks.json` as needed.
* Use this boilerplate as a starting point for ROS2 projects with **publishers, subscribers, services, and clients**.

---

## 📜 License

This project is licensed under the MIT License.
