#include <policy.h>
#include <lru.h>

#include <list>
#include <unordered_map>

template <class K>
LRU<K>::LRU(uint32_t _capacity) : capacity_ver{_capacity}, size_ver{0} {}

// evict
template <class K>
void LRU<K>::evict_and_add(K key)
{
    typename std::list<K>::iterator lru_elem = keys.begin();
    K lru_key = *lru_elem; // copy operation from the iterator
    keys.erase(lru_elem);
    k_map.erase(lru_key);
    std::cout<<"Evicted: "<<lru_key<<std::endl;

    // add
    add(key);
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
    if (size_ver >= capacity_ver)
        return;

    // always add keys at the end
    // std::list<K>::iterator it = ;
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

template class LRU<int>; 