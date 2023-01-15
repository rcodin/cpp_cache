#ifndef CACHE_HPP
#define CACHE_HPP

#include <common.hpp>
#include <eviction.hpp>

template <class T>
class cache {
protected:
	int size;
	int capacity;
private:
	// stores key and value
	unordered_map<int, string> kv;
	T eviction_obj;
public:
	cache(int _size);
	void put(int key, string val);
	void get(int key, string &val);
};

#endif