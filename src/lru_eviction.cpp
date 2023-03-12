#include <common.hpp>
#include <eviction.hpp>

int lru_eviction::evict() {
	int key = ordered_list.front();
	ordered_list.pop_front();
	key_pointers_map.erase(key);
	return key;
}

void lru_eviction::refresh(const int key) {
	auto &key_node = key_pointers_map[key];
	ordered_list.erase(key_node);
	ordered_list.push_back(key);
	auto last_itr = ordered_list.end();
	last_itr--;
	key_pointers_map[key] = last_itr;
}

void lru_eviction::insert(const int key) {
	ordered_list.push_back(key);
	auto &key_node = --ordered_list.end();
	key_pointers_map[key] = key_node;
}

void lru_eviction::dump_order() {
	for (auto const &v : ordered_list)
		std::cout << v << "\n";
}