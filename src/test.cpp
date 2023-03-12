#include <string>
#include <iostream>

#include <eviction.hpp>
#include <cache.hpp>
#include <memory>

using namespace std;

// Basic test to check if value can be reterieved

void test_1() {
	std::unique_ptr<cache<lru_eviction>> c = std::make_unique<cache<lru_eviction>>(10);
	std::string val;
	c->put(4, "e");
	c->get(4, val);
	std::cout<<val<<std::endl;
}

// Basic test to check what happens in case of searching with wrong key

void test_2() {
	std::unique_ptr<cache<lru_eviction>> c = std::make_unique<cache<lru_eviction>>(10);
	std::string val = "Empty Value";
	c->put(4, "e");
	c->get(5, val);
	std::cout<<val<<std::endl;
}

// Check eviction logic

void test_3() {
	std::unique_ptr<cache<lru_eviction>> c = std::make_unique<cache<lru_eviction>>(2);
	c->put(4, "e");
	c->put(5, "f");
	c->put(6, "g");

	std::string val = "Empty Value";
	val = "Empty Value";
	c->get(4, val);
	cout<<"key: "<<4<<" val: "<<val<<std::endl;
	val = "Empty Value";
	c->get(5, val);
	cout<<"key: "<<5<<" val: "<<val<<std::endl;
	val = "Empty Value";
	c->get(6, val);
	cout<<"key: "<<6<<" val: "<<val<<std::endl;
	c->dump_order();
}

int main() {
	test_1();
	test_2();
	test_3();
}
