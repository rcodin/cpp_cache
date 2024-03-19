// comparision
// constructors and efficient copy

template<class T>
class Key {
Private:
    T key;
public:
    Key(T _key) {
        this->key = _key;
    }
    bool operator==(const Key& k1, const Key& k2) {
        return k1.key == k2.key;
    }
};