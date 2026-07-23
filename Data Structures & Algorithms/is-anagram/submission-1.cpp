class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;

        if (s.length() != t.length()) 
            return false;

        for (const auto& c:s) 
            mp[c]++;
        
        for (const auto& c:t) {
            if (mp.find(c) == mp.end() || mp[c] <= 0)
                return false;
            
            mp[c]--;
        }

        return true;
    }
};
