class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     int n =nums1.size();
     int m =nums2.size();
     vector<int>ans;
     for(int i=0;i<n;i++){
        ans.push_back(nums1[i]);
     }
     for(int j =0;j<m;j++){
            ans.push_back(nums2[j]);
        }
     sort(ans.begin(),ans.end()); 
    if(ans.size()%2==1){
    return ans[ans.size()/2];
     }
     else{
     return (ans[ans.size()/2-1] + ans[ans.size()/2]) / 2.0;
}
    }
};