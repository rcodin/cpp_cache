CCC = g++ # Flag for implicit rules
SRCS = lib/cache.cpp policies/lru.cpp
CFLAGS = -O3  -fPIC -shared  -std=c++11
TARGET = libcppc.so
OBJS = $(SRCS:.c=.o)
INC = -Iinclude/

cpp_cache_lib:
	$(CCC) $(CFLAGS) $(INC) -shared -o $(TARGET) $(OBJS)

main:
	$(CCC) $(INC) src/main.cpp -L. -o main  -lcppc
clean:
	rm -f main libcppc.so
