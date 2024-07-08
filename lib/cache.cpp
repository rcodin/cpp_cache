#include <policy.h>
#include <common.h>

#include <lru.h>
#include <unordered_map>
#include <cache.h>

template <class K, class V>
V Cache<K, V>::get(K key, bool &status)
{
	if (store.find(key) == store.end())
	{
		status = false;
		V v;
		return v;
	}
	// Update Cache
	pol->update(key);

	status = true;
	return store[key];
}

template <class K, class V>
void Cache<K, V>::put(K key, V val, bool &status)
{
	eviction_status<K> evc_status;
	// if size == capacity then evict and store
	if (size == capacity && (store.find(key) == store.end()))
	{
		store[key] = val;
		std::cout<<"Evicted"<<std::endl;
		evc_status = pol->write(key);
		if (evc_status.evicted == true)
			store.erase(evc_status.key);
		std::cout<<evc_status.key<<std::endl;
	}
	else if (size == capacity)
	{
		store[key] = val;
		pol->update(key);
	}
	else
	{
		store[key] = val;
		pol->write(key);
		size++;
	}

	status = true;
}


template <class K, class V>
Cache<K, V>::Cache(int _capacity, policies _p)
{
	capacity = _capacity;
	switch (_p)
	{
	case policies::lru:
		pol = static_cast<Policy<K> *>(new LRU<K>(_capacity));
		break;

	default:
		break;
	}
}

template class Cache<int, std::string>;
