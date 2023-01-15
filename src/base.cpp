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
			eviction_obj.evict();
			eviction_obj.insert(key);
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