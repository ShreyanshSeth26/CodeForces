class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                 vector<vector<int>>& edges2) {
        int D1 = treeDiameter(edges1);
        int D2 = treeDiameter(edges2);
        int R1 = (D1 + 1) / 2;
        int R2 = (D2 + 1) / 2;
        return max({ D1, D2, R1 + 1 + R2 });
    }

private:
    int treeDiameter(const vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int u = farthestNode(0, adj).first;
        return farthestNode(u, adj).second;
    }

    pair<int,int> farthestNode(int src, const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);

        int farNode = src, farD = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] < 0) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if (dist[v] > farD) {
                        farD = dist[v];
                        farNode = v;
                    }
                }
            }
        }
        return {farNode, farD};
    }
};
