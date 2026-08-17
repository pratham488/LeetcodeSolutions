class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        if (n <= 1) return 0;

        vector<unordered_set<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        // Step 1: repeatedly remove coin-less leaves
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1 && coins[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int nei : graph[node]) {
                graph[nei].erase(node);
                if (graph[nei].size() == 1 && coins[nei] == 0) q.push(nei);
            }
            graph[node].clear();
        }

        // Step 2: remove two more layers of leaves (radius-2 reachable)
        for (int round = 0; round < 2; round++) {
            vector<int> leaves;
            for (int i = 0; i < n; i++) {
                if (graph[i].size() == 1) leaves.push_back(i);
            }
            for (int leaf : leaves) {
                for (int nei : graph[leaf]) {
                    graph[nei].erase(leaf);
                }
                graph[leaf].clear();
            }
        }

        // Count remaining edges
        int remainingEdges = 0;
        for (int i = 0; i < n; i++) {
            remainingEdges += graph[i].size();
        }
        remainingEdges /= 2;

        return remainingEdges * 2;
    }
};