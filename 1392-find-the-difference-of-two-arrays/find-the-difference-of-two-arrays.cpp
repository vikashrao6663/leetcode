class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {

        unordered_set<int> s1(a.begin(), a.end());
        unordered_set<int> s2(b.begin(), b.end());

        vector<int> x, y;

        for(int v : s1)
            if(!s2.count(v)) x.push_back(v);

        for(int v : s2)
            if(!s1.count(v)) y.push_back(v);

        return {x, y};
    }
};