CCC = g++ # Flag for implicit rules
SRCS = lib/cache.cpp policies/lru.cpp
CFLAGS = -O3  -fPIC
TARGET = libcppc.so
OBJS = $(SRCS:.c=.o)
INC = -Iinclude/

cpp_cache_lib:
	$(CCC) $(CFLAGS) $(INC) -shared -o $(TARGET) $(OBJS)

main:
	$(CCC) $(INC) src/main.cpp -L. -o main  -lcppc
clean:
	rm -f main


	g++ -Wall -g -fPIC -c -Iinclude/ lib/cache.cpp policies/lru.cpp
	g++ -shared -Wl,-soname,libcat.so.1 -o libcat.so.1 cache.o lru.o


	g++ -Iinclude/ -Wall -g -c src/main.cpp
	g++ -Wall -Wl,-rpath,. -o main main.o libcat.so.1