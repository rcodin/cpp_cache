#include <unordered_ma>
#include <string>
#include <list>

using std::unordered_map ;
using std::string;
using std::list;

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
		key_pointers_map[key] = ordered_list.push_back(key) ;
	}

	void erase(const int key) {
		ordered_list.erase(key_node);
		key_pointers_map.erase(key);
	}
};

