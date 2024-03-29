# ROS2 Learning

There are two packages here, temp1_pkg and temp2_pkg.
temp1_pkg package exports its include directory and library.
While temp2_pkg package depends on temp1_pkg.

## Usage
```bash
ros2 run temp1_pkg temp1_pkg_node
```

```bash
ros2 run temp2_pkg temp2_pkg_node
```

The above should work!
