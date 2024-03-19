#ifndef CACHE_H_
#define CACHE_H_

#include <common.h>
#include <policy.h>

template<class K, class V>
class Cache {
private:
    Policy<K> *pol;
	uint32_t capacity;
	uint32_t size;
	std::unordered_map<K, V> store;

public:
	V get(K key, bool &status);
	void put(K key, V val, bool &status);
	Cache(int _capacity, policies _p);
};

#endif  // CACHE_H_