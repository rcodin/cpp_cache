CC=g++

INC = -I/home/roni/git_repos/cpp_cache/inc
CFLAGS = -Wall -g

all:
	$(CC) $(INC) $(CFLAGS) src/lru_eviction.cpp src/base.cpp src/test.cpp -o lru_test
