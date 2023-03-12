#include <common.hpp>
#include <cache.hpp>
#include <eviction.hpp>

template <class T> cache<T>::cache(int _size) {
	this->capacity = _size;
	this->size = 0;
}

template <class T> void cache<T>::put(int key, std::string val) {
	if (kv.find(key) != kv.end()) {
		eviction_obj.refresh(key);
	} else {
		if (size == capacity) {
			int r_key = eviction_obj.evict();
			// std::cout<<"Evict"<<std::endl;
			eviction_obj.insert(key);
			kv.erase(r_key);
		} else {
			size++;
			eviction_obj.insert(key);
		}
	}
	kv[key] = val;
}

template <class T> void cache<T>::get(int key, std::string &val) {
	if (kv.find(key) == kv.end())
		return;

	eviction_obj.refresh(key);
	val = kv[key];
}

template <class T> void cache<T>::dump_order() {
	eviction_obj.dump_order();
}

template class cache<lru_eviction>; 
