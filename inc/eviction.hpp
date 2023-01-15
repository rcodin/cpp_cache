#ifndef EVICTION_HPP
#define EVICTION_HPP

class eviction {
public:
	virtual void evict() = 0;
	virtual void refresh(const int key) = 0;
	virtual void insert(const int key) = 0;
};
class lru_eviction;

#endif
