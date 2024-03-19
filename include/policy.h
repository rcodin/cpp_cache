#ifndef POLICY_H_
#define POLICY_H_

#include <common.h>

template<class K>
class Policy {
private:
public:
    // evict
    virtual void evict_and_add(K key) = 0;
    // update a key
    virtual void update(K key) = 0;
    // add a key
    virtual void add(K key) = 0;
    virtual uint32_t size() = 0;
    virtual uint32_t capacity() = 0;
    virtual void view() = 0;
};

enum class policies : char
{
    lru = 'l'
};

#endif //POLICY_H_