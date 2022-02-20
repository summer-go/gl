# 设置cmake 最小版本为3.20，这个无所谓，只要设置的版本能跑的起来就行，一般不会报错
cmake_minimum_required(VERSION 3.20)
project(summerGL)
# 设置c++ 标准为c++ 14
set(CMAKE_CXX_STANDARD 14)
# 链接本地库，用到了系统库里的zip
LINK_DIRECTORIES(/usr/local/lib)
# 编译子工程 glfw
add_subdirectory(third-part/glfw-3.3.6)
# 链接glfw库
link_libraries(glfw)

# 编译子工程assimp
add_subdirectory(third-part/assimp-5.0.1)
# 链接assimp库
link_libraries(assimp)

#编译子工程glm
add_subdirectory(third-part/glm-0.9.9.8)
#链接glm库
link_libraries(glm)

# 添加要编译的源文件
set(SRCS src/glad.c )
# 编译主工程
add_executable(${PROJECT_NAME} ${SRCS} main.cpp )

# 配置root_directory，利用cmake的机制，动态生成项目根目录的读取类
configure_file(configuration/root_directory.h.in configuration/root_directory.h)
# 设置 头文件include目录
include_directories(${CMAKE_BINARY_DIR}/configuration)

# 设置第三方库的头文件导入目录
set(THIRD_PARTY_INC
        render/include
        third-part/glfw-3.3.6/include/
        third-part/glad/include/
        third-part/assimp-5.0.1/include
        third-part/glm-0.9.9.8
        third-part/stb-master)

message(STATUS ${THIRD_PARTY_INC})

# 导入第三方头文件
target_include_directories(${PROJECT_NAME} PUBLIC ${THIRD_PARTY_INC})

