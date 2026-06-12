class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,string>>v;
        int n =strs.size();
        for(int i =0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());

            v.push_back({temp,strs[i]});
        }
        sort(v.begin(),v.end());
        vector<vector<string>> ans;
        int i =0;
        while(i<v.size()){
            vector<string> group;
            string key=v[i].first;

            while(i<v.size()&& v[i].first==key){
                group.push_back(v[i].second);
                i++;
            }
            ans.push_back(group);
        }
        return ans;
    }
};