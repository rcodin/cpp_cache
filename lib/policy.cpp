class Policy {
	virtual int get(int key, bool &status);
	virtual void put(int key, int val, bool &status);
	virtual void evict(int key);
	Cache(int size);
};