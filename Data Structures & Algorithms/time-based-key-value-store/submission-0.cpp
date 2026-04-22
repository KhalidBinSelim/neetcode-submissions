class TimeMap {
public:
    unordered_map<string, unordered_map<int, vector<string>>> key_store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key_store[key][timestamp].push_back(value);
    }
    
    string get(string key, int timestamp) {
        if (key_store.find(key) == key_store.end()) return "";
        int seen = 0;
        for (const auto &[time, value]: key_store[key]) {
            if (time <= timestamp) seen = max(seen, time);
        }
        if (seen == 0) return "";
        else return key_store[key][seen].back();
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */