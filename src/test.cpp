#include <string>

#include <eviction.hpp>
#include <cache.hpp>


int main() {
	cache<lru_eviction> c (40);
	std::string val;
	c.put(4, val);
	c.get(4, val);
}
