class Cache {
public:
	int get(int key, bool &status);
	void put(int key, int val, bool &status);
	void evict(int key);
	Cache(int size);
};
