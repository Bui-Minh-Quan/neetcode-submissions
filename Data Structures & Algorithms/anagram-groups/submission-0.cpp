class Solution {
public:
    string sort_characters(string word) {
        sort(word.begin(), word.end());

        return word;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const auto& str:strs) {
            string temp = sort_characters(str);
            if (mp.find(temp) != mp.end()) {
                mp[temp].push_back(str);
                continue;
            } 

            mp[temp] = {str};
        }

        vector<vector<string>> ans;

        for (const auto& [key, value]:mp) {
            ans.push_back(value);
        }

        return ans;
    }
};
