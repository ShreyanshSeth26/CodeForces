class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.emplace(0, 0, 0);

        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;

        while (!pq.empty()) {
            auto [currEffort, r, c] = pq.top();
            pq.pop();

            if (r == rows - 1 && c == cols - 1)
                return currEffort;

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int diff = abs(heights[nr][nc] - heights[r][c]);
                    int nextEffort = max(currEffort, diff);
                    if (nextEffort < effort[nr][nc]) {
                        effort[nr][nc] = nextEffort;
                        pq.emplace(nextEffort, nr, nc);
                    }
                }
            }
        }

        return 0;
    }
};
