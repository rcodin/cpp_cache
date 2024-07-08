#include <policy.h>
#include <lru.h>

#include <list>
#include <unordered_map>

template <class K>
LRU<K>::LRU(uint32_t _capacity) : capacity_ver{_capacity}, size_ver{0} {}

// evict
template <class K>
eviction_status<K> LRU<K>::evict()
{
    eviction_status<K> ret;

    // eviction
    typename std::list<K>::iterator lru_elem = keys.begin();
    K lru_key = *lru_elem; // copy operation from the iterator
    keys.erase(lru_elem);
    k_map.erase(lru_key);
    std::cout<<"Evicted: "<<lru_key<<std::endl;

    ret.evicted = true;
    ret.key = lru_key;
    return ret;
}

template <class K>
eviction_status<K> LRU<K>::write(K key)
{
    eviction_status<K> ret;
    ret.evicted = false;
    if (full()) {
    	ret = evict();
        size_ver--;
    }
    // add
    add(key);
    size_ver++;
    return ret;
}
// update a key
template <class K>
void LRU<K>::update(K key)
{
    // erase element and then add
    typename std::list<K>::iterator elem = k_map[key];
    keys.erase(elem);
    keys.push_back(key);

    // add
    typename std::list<K>::iterator last = keys.end();
    --last;
    k_map[key] = last;
}
// add a key
template <class K>
void LRU<K>::add(K key)
{
    eviction_status<K> ret;
    if (size_ver >= capacity_ver)
        return;

    keys.push_back(key);
    typename std::list<K>::iterator last = keys.end();
    --last;
    k_map[key] = last;
}

template <class K>
uint32_t LRU<K>::size()
{
    return size_ver;
}

template <class K>
uint32_t LRU<K>::capacity()
{
    return capacity_ver;
}

template <class K>
void LRU<K>::view()
{

}

template <class K>
bool LRU<K>::full()
{
    return capacity_ver <= size_ver;
}

template class LRU<int>;
