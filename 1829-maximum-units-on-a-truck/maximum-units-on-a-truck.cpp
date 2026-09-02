bool cmp(vector<int>&a,vector<int>&b){
    return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truck) {
      sort(box.begin(),box.end(),cmp);
      int profit=0;
      for(int i =0;i<box.size();i++){
        if(box[i][0]<=truck){
            profit +=box[i][0]*box[i][1];
            truck -=box[i][0];
        }
        else{
            profit +=truck*box[i][1];
            truck =0 ;
        }
        if(truck == 0) break;
      }  
      return profit;
    }
};