class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int n = intervals.size();

        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {

            if(vis[i]) continue;

            int start = intervals[i][0];
            int end = intervals[i][1];

            for(int j = i + 1; j < n; j++) {

                if(intervals[j][0] <= end) {

                    end = max(end, intervals[j][1]);
                    vis[j] = true;

                } else {
                    break;
                }
            }

            ans.push_back({start, end});
        }

        return ans;
    }
};