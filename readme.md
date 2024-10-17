# 参考模板

## 文档链接

https://z1eac6eifxs.feishu.cn/wiki/QX6ywdJGMiDla6k17KYckM4FnSc?from=from_copylink

## 项目拉取

```shell
git clone --recursive https://github.com/viys/oopc_cmake_stu
```

## Kconfig 依赖

```shell
# 更新 apt
sudo apt update
sudo apt upgrade
# 安装工具包
sudo apt install python3-kconfiglib
sudo apt-get install libncurses-dev kconfig-frontends
```

## 运行项目

### 项目配置

```shell
mkdir build
cd build
cmake ..
```

### Kconfig 配置

note: ./project/prj.conf 中的配置参数为最高优先级需要手动更改

```shell
make menuconfig
```

```shell
 /home/viys/oopc_cmake_stu/build/prj.conf - project setting
 ────────────────────────────────────────────────────────────────────────────────────────────────────────
  ┌───────────────────────────────────────── project setting ─────────────────────────────────────────┐
  │  Arrow keys navigate the menu.  <Enter> selects submenus ---> (or empty submenus ----).           │  
  │  Highlighted letters are hotkeys.  Pressing <Y> includes, <N> excludes, <M> modularizes features. │  
  │  Press <Esc><Esc> to exit, <?> for Help, </> for Search.  Legend: [*] built-in  [ ] excluded      │  
  │  <M> module  < > module capable                                                                   │  
  │ ┌───────────────────────────────────────────────────────────────────────────────────────────────┐ │  
  │ │            (H00-x.x.x) 设置固件版本号 (NEW)                                                   │ │  
  │ │                固件配置  --->                                                                 │ │  
  │ │                                                                                               │ │  
  │ │                                                                                               │ │  
  │ │                                                                                               │ │  
  │ │                                                                                               │ │  
  │ │                                                                                               │ │  
  │ └───────────────────────────────────────────────────────────────────────────────────────────────┘ │  
  ├───────────────────────────────────────────────────────────────────────────────────────────────────┤  
  │                     <Select>    < Exit >    < Help >    < Save >    < Load >                      │  
  └───────────────────────────────────────────────────────────────────────────────────────────────────┘  
```

在配置完成后在构建生成 prj.conf 文件以及在 project 目录下生成 my_config.h 头文件

### 项目构建

```shell
make
```

### 运行二进制文件

```shell
./oopc
```

## 运行测试历程

以 animal 为例

### 配置

```shell
mkdir class_lib/animal_class/test/build
cd class_lib/animal_class/test/build/
cmake ..
```

### 构建并运行

```shell
make
./test
```

