# C++使用SFML图形库实现贪吃蛇小游戏

## Windows运行环境

游戏运行环境依赖第三方库SFML，请至官网下载并确认包含了以下动态链接库：
```
sfml-audio
sfml-graphics
sfml-main
sfml-network
sfml-system
sfml-window
```

确认完毕后，修改`CMakelist.txt`文件第8行内容
``` cmake
include_directories(C:/SFML/include)
```
为`SFML/include`的安装路径，修改10-15行内容
```
find_library(audio sfml-audio C:/SFML/lib)
find_library(graphics sfml-graphics C:/SFML/lib)
find_library(main sfml-main C:/SFML/lib)
find_library(network sfml-network C:/SFML/lib)
find_library(system sfml-system C:/SFML/lib)
find_library(window sfml-window C:/SFML/lib)
```
为以上动态链接库的安装路径`SFML/lib`。

修改完毕后，推荐使用`MinGW`工具链编译，vs2019的编译器不同，对编译错误的检查不同。进入项目根目录，依次输入如下命令编译运行
``` bash
CMake -G "MinGW Makefiles"
mingw32-make
```
在`/bin`目录下生成可执行文件`game.exe`，运行即可
``` bash
./bin/game.exe
```