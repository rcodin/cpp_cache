// Driver code
#include <iostream>
#include <list>
#include <unordered_map>
// Basic LRU in memory cache

namespace cache {
class Cache {
private:
	// linked list
	// hashmap
	// 
	uint64_t size;
	uint64_t capacity;
	// stores the keys
	std::list<int> ordered_list;
	// key, data
	std::unordered_map<int, std::list<int>::iterator> lookup_table;
	std::unordered_map<int, std::string> storage;
	// write an eviction function
	// evicts a single element out of the cache
	void evict() {
		int key = ordered_list.back();
		// remove the element from list
		ordered_list.pop_back();
		// remove the element from lookup table
		lookup_table.erase(key);
	}
	void insert(int key, std::string val) {
		ordered_list.push_front(key);
		lookup_table[key] = ordered_list.begin();
		storage[key] = val;
		size++;
	}
public:
	Cache(const uint64_t _size) {
		size = 0;
		capacity = _size;
	}
	void get(int key, std::string &val) {
		// get val
		if (lookup_table.find(key) == lookup_table.end()) {
			// return error;
			return;
		}

		// update the recency
		std::list<int>::iterator list_ptr = lookup_table[key];
		ordered_list.erase(list_ptr);
		// update lookup table
		ordered_list.push_front(key);
		lookup_table[key] = ordered_list.begin();
		// return val
		val = storage[key];
	}
	void put(int key, std::string val) {
		// if key already present then update
		if (lookup_table.find(key) != lookup_table.end()) {
			std::list<int>::iterator list_ptr = lookup_table[key];
			ordered_list.erase(list_ptr);
			ordered_list.push_front(key);
		} else {
			if (capacity == size) {
				evict();
				--size;
			}
			//insert
			insert(key, val);
		}
		// update recency structure
		// 
	}
};

};

int main() {
}
