#### 1 、使用ROS功能包前，需要保证已经安装好了固件库，可以参考“Python基础控制课程”的第三节的内容-安装Rosmaster驱动库

#### 2、创建，初始化，编译一个ROS工作空间（driver_ws为例）

##### 终端输入，

```
mkdir driver_ws
cd    driver_ws
mkdir src
cd src
```

#### 3、把文件夹下的所有功能包文件夹，复制粘贴到ROS工作空间的src文件夹下，然后回到driver_ws，输入以下命令编译，

```
colcon build
```

#### ![image-20230529192823753](image-20230529192823753.png)

#### 4、添加功能包路径到环境变量中

**终端输入，**

```
sudo gedit ./.bashrc	
```

**把下边的内容，粘贴到文件末端，**

```python
source ~/driver_ws/install/setup.bash
```

#### 5、保存，退出，输入以下命令刷新环境变量

```
source ~/.bashrc
```

#### 6、编译可能需要安装的依赖

```
#以ros-foxy为例
sudo apt install ros-foxy-geographic-*
sudo apt install libgeograph*
```

