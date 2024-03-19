#ifndef LRU_H_
#define LRU_H_

#include <list>

#include <common.h>

template<class K>
class LRU: public Policy<K> {
private:
    std::list<K> keys;
    std::unordered_map<K, typename std::list<K>::iterator> k_map;
    uint32_t size_ver;
    uint32_t capacity_ver;
public:
    LRU(uint32_t _capacity);
    // evict
    void evict_and_add(K key);
    // update a key
    void update(K key);
    // add a key
    void add(K key);
    uint32_t size();
    uint32_t capacity();
    void view();
};

// template<int, int>
// class LRU;

#endif  // LRU_H_