class Solution {
public:
    vector<vector<int>> g;
    vector<bool> vis;
    int nodes, degreeSum;

    void dfs(int u) {
        vis[u] = true;
        nodes++;
        degreeSum += g[u].size();

        for (int v : g[u]) {
            if (!vis[v])
                dfs(v);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        g.resize(n);
        vis.assign(n, false);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                nodes = 0;
                degreeSum = 0;
                dfs(i);

                int edgeCnt = degreeSum / 2;
                if (edgeCnt == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};