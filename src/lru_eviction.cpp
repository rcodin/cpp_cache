#include <common.hpp>
#include <eviction.hpp>

class lru_eviction: public eviction {
private:
	unordered_map<int, list<int>::iterator> key_pointers_map;
	list<int> ordered_list;
public:
	void evict() {
		int key = ordered_list.front();
		ordered_list.pop_front();
		key_pointers_map.erase(key);
	}

	void refresh(const int key) {
		auto &key_node = key_pointers_map[key];
		ordered_list.erase(key_node);
		ordered_list.push_back(key);
		auto last_itr = ordered_list.end();
		last_itr--;
		key_pointers_map[key] = last_itr;
	}

	void insert(const int key) {
		ordered_list.push_back(key);
		auto &key_node = ordered_list.end() - 1;
		key_pointers_mapp[key] = key_node;
	}
};

