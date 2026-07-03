class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n,0);

        int maxi = 0;

        for(auto &e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            indegree[e[1]]++;
            maxi = max(maxi,e[2]);
        }

        queue<int> q;
        vector<int> topo;
        vector<int> deg = indegree;

        for(int i = 0; i < n; i++){
            if(deg[i] == 0)
                q.push(i);
        }

        while(q.empty() == false){

            int u = q.front();
            q.pop();

            topo.push_back(u);

            for(auto &it : adj[u]){
                int v = it.first;
                deg[v]--;

                if(deg[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit){

            const long long INF = 1000000000000000000LL;

            vector<long long> dist(n, INF);
            dist[0] = 0;

            for(int u : topo){

                if(dist[u] == INF)
                    continue;

                if(u != 0 && u != n - 1 && online[u] == false)
                    continue;

                for(auto &it : adj[u]){

                    int v = it.first;
                    int w = it.second;

                    if(w < limit)
                        continue;

                    if(v != n - 1 && online[v] == false)
                        continue;

                    if(dist[v] > dist[u] + w)
                        dist[v] = dist[u] + w;
                }
            }

            return dist[n - 1] <= k;
        };

        int low = 0;
        int high = maxi;
        int ans = -1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(check(mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};