class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto& num:nums) {
            if (mp.find(num) != mp.end())
                return true;
            mp[num]++;
        }

        return false;
    }
};