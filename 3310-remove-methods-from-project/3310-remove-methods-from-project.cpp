class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        // Build graph
        vector<vector<int>> adj(n);

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // Mark all suspicious (buggy) methods using BFS
        vector<bool> bug(n, false);

        queue<int> q;
        q.push(k);
        bug[k] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (!bug[nei]) {
                    bug[nei] = true;
                    q.push(nei);
                }
            }
        }

        // Original methods
        vector<int> allMethods;
        for (int i = 0; i < n; i++)
            allMethods.push_back(i);

        // Check if any non-bug method invokes a bug method
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!bug[u] && bug[v]) {
                return allMethods;
            }
        }

        // Return only remaining (non-buggy) methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!bug[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};