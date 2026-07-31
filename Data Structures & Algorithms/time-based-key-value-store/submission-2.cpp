#include <string>
#include <vector>
#include <unordered_map>

class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> mp;

public:
    TimeMap() {}

    void set(std::string key, std::string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    std::string get(std::string key, int timestamp) {
        // Avoid creating an empty vector entry if key doesn't exist
        if (!mp.contains(key)) return "";

        const auto& v = mp[key];
        int left = 0;
        int right = v.size() - 1;
        std::string ans = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (v[mid].first <= timestamp) {
                ans = v[mid].second; // Valid candidate! Save it
                left = mid + 1;      // Search right half for a potentially closer timestamp
            } else {
                right = mid - 1;     // Too large, search left half
            }
        }

        return ans;
    }
};