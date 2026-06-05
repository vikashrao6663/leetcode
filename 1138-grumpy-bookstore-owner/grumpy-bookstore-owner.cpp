class Solution {
public:
    int maxSatisfied(vector<int>& arr, vector<int>& grumpy, int k) {
        int n = arr.size();
        int preloss=0;
        for(int i = 0 ;i<k;i++){
            if(grumpy[i]==1) preloss +=arr[i];
        }
        int maxloss=preloss;
        int maxidx=0;
        int i =1;
        int j = k ;
        while(j<n){
           int currloss = preloss;
           if(grumpy[j]==1) currloss +=arr[j];
           if(grumpy[i-1]==1) currloss -=arr[i-1];
            if(maxloss<currloss){
                maxloss=currloss;
                maxidx =i;
            }
            preloss=currloss;
            j++;
            i++;
        }
            for(int i =maxidx;i<maxidx+k;i++){
                grumpy[i]=0;
            }
            int sum = 0;
            for(int i=0;i<n;i++){
                if(grumpy[i]==0) sum +=arr[i];
            }
            return sum;
    }
};