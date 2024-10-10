# 定义变量
CXX = g++
CXXFLAGS = -Wall -Wextra -I./include -I./include/curl -I./include/iclient
LDFLAGS = -L./lib -llua -lcjson -liclient -lcurl  -lpthread -ldl

# 定义目标和源文件
TARGET = demo
SRCS = main.cpp

# 规则：生成目标文件
all: $(TARGET)

# 链接目标文件
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# 清理生成的文件
clean:
	rm -f $(TARGET)
