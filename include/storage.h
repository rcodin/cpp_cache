#ifndef STORAGE_H_
#define STORAGE_H_

#include <common.h>

// class to optimize logic for storage

// TODO: add support for in memory and in NVM storage

// Currently unused: please use it later when we have sophisticated storage mechanism

template<class K, typename V>
class Storage {
private:
    K key;
    V val;
public:
    Storage(K _key, V _val): val(_val), key(_key) {

    }
    void view() {

    }
    V get_val() {
        return val;
    }
    // TODO: figure out efficient way to pass variable
    void update(V _val) {
        val = _val;
    }
};

#endif // STORAGE_H_