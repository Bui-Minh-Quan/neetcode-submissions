class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char task : tasks)
            ++freq[task - 'A'];

        int maxFreq = *max_element(freq.begin(), freq.end());

        int countMaxFreq = 0;

        for (int f : freq) {
            if (f == maxFreq)
                ++countMaxFreq;
        }

        int ans = (maxFreq - 1) * (n + 1) + countMaxFreq;

        return max(ans, (int)tasks.size());
    }
};