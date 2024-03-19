#include <policy.h>

template<class K, typename V>
class LRU: public Policy<K, V> {
private:
    std::list<K> keys;
    std::unordered_map<K, std::list<K>::iterator> k_map;
    uint32_t size;
    uint32_t capacity:
public:
    // evict
    void evict_and_add(K key) {
        // evict
        std::list<K>::iterator lru_elem = keys.begin();
        K key = *lru_elem; // copy operation from the iterator
        k_map.erase(lru_elem);
        unordered_map.erase(key);
    
        // add
        add(key);

    }
    // update a key
    void update(K key) {
        // erase element and then add
        std::list<K>::iterator elem = k_map[key];
        keys.erase(elem);
        keys.push_back(key);
        
        // add
        std::list<K>::iterator last = keys.end();
        --last;
        k_map[key] = last;
    }
    // add a key
    void add(K key) {
        if (size >= capacity)
            return;

        // always add keys at the end
        // std::list<K>::iterator it = ;
        keys.push_back(key);
        std::list<K>::iterator last = keys.end();
        --last;
        k_map[key] = last;
    }
    uint32_t size() {
        return size;
    }
    uint32_t capacity() {
        return capacity;
    }
    void view() {

    }
};