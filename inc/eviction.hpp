#ifndef EVICTION_HPP
#define EVICTION_HPP
#include <common.hpp>

class eviction {
public:
	virtual void evict() = 0;
	virtual void refresh(const int key) = 0;
	virtual void insert(const int key) = 0;
};

class lru_eviction: public eviction {
private:
	unordered_map<int, list<int>::iterator> key_pointers_map;
	list<int> ordered_list;
public:
	void evict();
	void refresh(const int key);
	void insert(const int key);
};

#endif
