class Solution {
private:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        
        return find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b)
            parent[b] = a;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;

        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (const auto& e:edges) {
            if (find(e[0]) == find(e[1])) {
                ans = e;
            } else {
                unite(e[0], e[1]);
            }
        }

        return ans;
    }
};
