#ifndef EVICTION_HPP
#define EVICTION_HPP
#include <common.hpp>

class eviction {
public:
	virtual int evict() = 0;
	virtual void refresh(const int key) = 0;
	virtual void insert(const int key) = 0;
	virtual void dump_order() = 0;
};

class lru_eviction: public eviction {
private:
	unordered_map<int, list<int>::iterator> key_pointers_map;
	list<int> ordered_list;
public:
	int evict();
	void refresh(const int key);
	void insert(const int key);
	void dump_order();
};

#endif
