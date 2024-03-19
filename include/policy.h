template<class K, typename V>
class Policy {
private:
public:
    // evict
    void evict();
    // update a key
    void update(T key);
};