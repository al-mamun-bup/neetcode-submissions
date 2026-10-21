class TimeMap {
private:
        unordered_map<string,vector<pair<int,string>>> keyStore;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int lo = 0, hi = values.size() - 1;
        string res = "";
        while(hi >= lo){
            int mid = lo + (hi-lo) / 2;
            if(values[mid].first <= timestamp){
                res = values[mid].second;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }

        return res;
    }
};
