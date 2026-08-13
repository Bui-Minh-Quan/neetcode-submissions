class Solution {
public:
    int ladderLength(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.contains(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        int distance = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return distance;

                for (int j = 0; j < word.size(); ++j) {
                    char original = word[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original)
                            continue;

                        word[j] = c;

                        if (words.contains(word)) {
                            words.erase(word);
                            q.push(word);
                        }
                    }

                    word[j] = original;
                }
            }

            ++distance;
        }

        return 0;
    }
};