#ifndef POLICY_H_
#define POLICY_H_

#include <common.h>

template <typename K>
struct eviction_status {
    bool evicted;
    K key;
};

/*
 * Policy is a virtual class
 * So, no defination of policy is needed.
 * There is cpp file corresponding it
 */

template<class K>
class Policy {
private:
    virtual eviction_status<K> evict() = 0;
    // add a key
    virtual void add(K key) = 0;
public:
    // evict
    virtual eviction_status<K> write(K key) = 0;
    // update a key
    virtual void update(K key) = 0;
    virtual uint32_t size() = 0;
    virtual uint32_t capacity() = 0;
    virtual void view() = 0;
};

enum class policies : char
{
    lru = 'l'
};

#endif //POLICY_H_
