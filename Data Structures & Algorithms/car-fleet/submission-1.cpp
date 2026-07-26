class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vt;
        stack<float> st;

        const int n = position.size();
        for (int i = 0; i < n; i++) {
            vt.push_back({position[i], speed[i]});
        }

        sort(vt.begin(), vt.end(), greater<>());

        for (const auto& v:vt) {
            float time = static_cast<float>(target - v.first) / v.second;
            if (st.empty() || st.top() < time)
                st.push(time);
        }

        return st.size();
    }
};
