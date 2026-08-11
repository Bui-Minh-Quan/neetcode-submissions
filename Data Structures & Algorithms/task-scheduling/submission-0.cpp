class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (const auto& task:tasks) {
            int index = task - 'A';
            ++freq[index]; 
        }

        priority_queue<pair<int, int>> pq;
        int circles = 0;

        for (int i = 0; i < 26; i++) 
            if (freq[i] > 0)
                pq.push({freq[i], i});
        
        int ans = 0;
        int chunk = 0;
        while (!pq.empty()) {
            ans = chunk * (n + 1);
            vector<pair<int, int>> temps;

            for (int i = 0; i <= n; i++) {
                if (pq.empty())
                    break;
                ++ans;
                auto [freq, task] = pq.top();
                pq.pop();
                --freq;
                if (freq > 0)
                    temps.push_back({freq, task});
            }

            ++chunk;

            for (const auto& [freq, task]:temps) 
                pq.push({freq, task});

        }

        return ans;
        

    }
};
