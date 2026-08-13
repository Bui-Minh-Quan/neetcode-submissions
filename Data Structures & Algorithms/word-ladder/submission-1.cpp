class Solution {
private:
    int diff(string a, string b) {
        int n = a.length();
        int d = 0;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                ++d;
            
        return d;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        set<string> visited;

        int dis = 1;
        q.push(beginWord);
        visited.insert(beginWord);

        while(!q.empty()) {
            
            int n = q.size();
            ++dis;

            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();
                for (auto& new_word:wordList) {
                    
                    if (visited.contains(new_word))
                        continue;
                    
                    if (diff(word, new_word) <= 1) {
                        if (new_word == endWord)
                            return dis;

                        visited.insert(new_word);
                        q.push(new_word);
                    }
                }
            }
        

        }


        return 0;
    }
};
