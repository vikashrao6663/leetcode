class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        // dist[i][j] = distance of cell (i,j) from the nearest thief
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;

        // -------------------------------
        // STEP 1 : Push all thief cells into queue
        // -------------------------------
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    dist[i][j] = 0;      // thief cell distance = 0
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        // -------------------------------
        // STEP 2 : Multi Source BFS
        // Find minimum distance of every cell from nearest thief
        // -------------------------------
        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                // Outside grid
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                // Already visited
                if (dist[nx][ny] != INT_MAX)
                    continue;

                // Distance = parent distance + 1
                dist[nx][ny] = dist[x][y] + 1;

                q.push({nx, ny});
            }
        }

        // ----------------------------------------------------
        // STEP 3 : Max Heap
        // Store {current path safeness, row, col}
        // Higher safeness should come out first.
        // ----------------------------------------------------
        priority_queue<vector<int>> pq;

        // Initially path safeness = dist of starting cell
        pq.push({dist[0][0], 0, 0});

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int safe = curr[0];
            int x = curr[1];
            int y = curr[2];

            // Skip if already processed
            if (vis[x][y])
                continue;

            vis[x][y] = true;

            // Destination reached
            // Since Max Heap is used,
            // first time reaching destination gives maximum answer
            if (x == n - 1 && y == n - 1)
                return safe;

            // Explore all 4 neighbours
            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if (vis[nx][ny])
                    continue;

                // Path safeness is always
                // minimum of previous path and new cell
                int newSafe = min(safe, dist[nx][ny]);

                pq.push({newSafe, nx, ny});
            }
        }

        return 0;
    }
};