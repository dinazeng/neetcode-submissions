class TimeMap {
public:

    unordered_map<string, map<int, string>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = timeMap[key].upper_bound(timestamp);
        return it == timeMap[key].begin() ? "" : prev(it)->second;
    }
};
