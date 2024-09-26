# 使用的编译器
CXX = g++
CXXFLAGS = -std=c++03 -I../include  # 指定使用C++03标准，并添加头文件路径

# 动态库名称和路径
LIB_NAME = libstreamprovider.so
LIB_PATH = .

# 编译动态库的源文件
LIB_SRCS = ./src/stream_provider.cpp

# 服务端可执行文件的源文件
SERVER_SRCS = ./src/server.cpp

# 默认目标
all: server $(LIB_NAME)

# 编译动态库
$(LIB_NAME): $(LIB_SRCS)
	$(CXX) $(CXXFLAGS) -fPIC -shared -o $(LIB_NAME) $(LIB_SRCS)

# 编译可执行文件，链接动态库并设置RPATH
server: $(SERVER_SRCS) $(LIB_NAME)
	$(CXX) $(CXXFLAGS) -o server $(SERVER_SRCS) -L$(LIB_PATH) -lstreamprovider -Wl,-rpath=$(LIB_PATH)

# 清理生成的文件
clean:
	rm -f server $(LIB_NAME)
