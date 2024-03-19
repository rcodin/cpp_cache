#include <iostream>

#include <common.h>
#include <cache.h>
#include <lru.h>
#include <string>
#include <policy.h>


int main() {
    Cache<int, std::string> cache(2, policies::lru);
    bool status = true;
    cache.put(4, "four", status);
    std::cout<<"status: "<<status<<std::endl;
    cache.put(3, "three", status);
    std::cout<<"status: "<<status<<std::endl;
    cache.put(2, "two", status);
    std::cout<<"status: "<<status<<std::endl;

    std::string val;
    val = cache.get(4, status);
    if (status == true)
	std::cout<<"status: "<<status<<" val: "<<val<<std::endl;
    val = cache.get(3, status);
    std::cout<<"status: "<<status<<" val: "<<val<<std::endl;
    val = cache.get(2, status);
    std::cout<<"status: "<<status<<" val: "<<val<<std::endl;
}
