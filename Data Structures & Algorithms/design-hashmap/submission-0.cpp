class MyHashMap {
private: vector<int> Hashmap;
public: 
    MyHashMap() : Hashmap (1000001, -1) {
        
    }
    
    void put(int key, int value) {
        if (key < 0 || key >= Hashmap.size()) {
            return;
        }
        Hashmap[key] = value;
    }
    
    int get(int key) {
        if (key < 0 || key >= Hashmap.size()) {
            return -1;
        }
        return Hashmap[key];
    }
    
    void remove(int key) {
        if (key < 0 || key >= Hashmap.size()) {
            return;
        }
        Hashmap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */