class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> key_store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key_store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &values = key_store[key];
        int l = 0, r = values.size() - 1;
        string res = "";
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (values[mid].first <= timestamp) {
                res = values[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */