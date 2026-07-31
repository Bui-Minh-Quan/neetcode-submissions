class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& v = mp[key];

        if (v.size() == 0)
            return "";
        
        const int n = v.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (left == right - 1) 
                break;

            if (v[mid].first == timestamp)
                return v[mid].second;
            
            if (v[mid].first > timestamp) // too large
                right = mid - 1;
            else // smaller, could be the right answer
                left = mid;
        }

        if (v[right].first <= timestamp)
            return v[right].second;

        if (v[left].first <= timestamp)
            return v[left].second;
        else
            return "";

    }
};
