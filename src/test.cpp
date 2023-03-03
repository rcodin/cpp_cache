#include <string>
#include <iostream>

#include <eviction.hpp>
#include <cache.hpp>
#include <memory>

int main() {
	std::unique_ptr<cache<lru_eviction>> c = std::make_unique<cache<lru_eviction>>(10);
	std::string val;
	c->put(4, "e");
	c->get(4, val);
	std::cout<<val<<std::endl;
}
