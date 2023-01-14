template <class T>
class cache {
protected:
	int size;
	int capacity;
private:
	// stores key and value
	unordered_map<int, string> kv;
	T eviction_obj;
public:
	cache() {
		this->capacity = size;
		this->size = 0;
	}

	void put(int key, string val) {
		if (kv.find(key) != kv.end()) {
			eviction_obj.refresh(key);
		} else {
			if (size == capacity()) {
				eviction_obj.evict();
				eviction_obj.insert(key);
			} else {
				size++;
				eviction_obj.insert(key);
			}
		}
		kv[key] = val;
	}

	void get(int key) {
		if (kv.find(key) == kv.end())
			return;

		eviction_obj.refresh(key);
		return kv[key];
	}
};
