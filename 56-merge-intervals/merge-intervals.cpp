class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort all the element given 
      sort(intervals.begin(),intervals.end());
      //ans store krge
      vector<vector<int>> ans;
      //first element ko ans mai push kr do 
      ans.push_back(intervals[0]); 
      //ek for loog chla kr 0 ko chod kr 1 se n tk traverse krge  
      for(int i =1;i<intervals.size();i++){
        //agr 1 element ke 2 point wala uske baad wale se bda ho to first wale ka first lege or 2nd wale ka last wala 
        if(intervals[i][0]<=ans.back()[1]){

            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
        else {
            ans.push_back(intervals[i]);
        }
      }
      return ans;
    }
};