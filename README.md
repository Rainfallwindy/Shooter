# Shooter# Shooter (2D 射击游戏)

这是一个基于 C++ 和 Raylib 图形库开发的 2D 俯视角射击小游戏。

## 技术栈
- C++ (面向对象与多文件工程)
- Raylib 图形库
- 采用标准工程目录结构（src/include分离）

## 功能特性
- WASD 控制玩家移动
- 鼠标左键向鼠标方向发射子弹
- 怪物带有加速度与摩擦力惯性追踪 AI
- AABB 矩形碰撞检测
- 子弹对象池管理（动态清理飞出屏幕的子弹）

## 如何运行
直接使用 Visual Studio 打开 `Shooter.slnx` 编译运行即可（依赖已包含在 `raylib` 文件夹中）。
