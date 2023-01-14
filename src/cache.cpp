// Driver code
#include <iostream>
#include <list>
#include <unordered_map>
#include <stdexcept>

// Basic LRU in memory cache

namespace cache {

using dll_int = std::list<int>;
using std::string;
using std::unordered_map;

class Cache {
private:
	// linked list
	// hashmap
	// 
	uint64_t size;
	uint64_t capacity;
	// stores the keys
	dll_int ordered_list;
	// key, data
	unordered_map<int, dll_int::iterator> lookup_table;
	unordered_map<int, string> storage;
	// write an eviction function
	// evicts a single element out of the cache
	void evict() {
		int key = ordered_list.back();
		// remove the element from list
		ordered_list.pop_back();
		// remove the element from lookup table
		lookup_table.erase(key);
	}
	void insert(int key, string val) {
		ordered_list.push_front(key);
		lookup_table[key] = ordered_list.begin();
		storage[key] = val;
		size++;
	}
public:
	Cache(const uint64_t _size) {
		if (_size == 0)
			throw std::length_error("Cache size must be non-zero");
		size = 0;
		capacity = _size;
	}
	void get(int key, string &val) {
		// get val
		if (lookup_table.find(key) == lookup_table.end()) {
			// return error;
			return;
		}

		// update the recency
		dll_int::iterator list_ptr = lookup_table[key];
		ordered_list.erase(list_ptr);
		// update lookup table
		ordered_list.push_front(key);
		lookup_table[key] = ordered_list.begin();
		// return val
		val = storage[key];
	}
	void put(int key, string val) {
		// if key already present then update
		if (lookup_table.find(key) != lookup_table.end()) {
			dll_int::iterator list_ptr = lookup_table[key];
			ordered_list.erase(list_ptr);
			ordered_list.push_front(key);
			lookup_table[key] = ordered_list.begin();
		} else {
			if (capacity == size) {
				evict();
				--size;
			}
			//insert
			insert(key, val);
		}
	}
	void dump_cache() {
		dll_int::iterator it = ordered_list.begin();
		for (; it != ordered_list.end(); ++it) {
			int key = *it;
			string val = storage[key];
			std::cout<<"key: "<<key<<" val: "<<val<<std::endl;
		}
	}
};

};

void run_tests() {
	cache::Cache c(3);
	c.put(1, "one");
	c.dump_cache();
	c.put(2, "two");
	c.put(3, "three");
	c.dump_cache();
	c.put(4, "four");
	c.dump_cache();
	std::string val;
	c.get(3, val);
	c.dump_cache();
	try {
		c = cache::Cache(0);
	} catch (std::exception &e) {
		std::cout<<e.what()<<std::endl;
	}
}

int main() {
	run_tests();
}
