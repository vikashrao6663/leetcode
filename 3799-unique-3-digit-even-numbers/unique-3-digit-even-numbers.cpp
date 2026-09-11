class Solution {
public:
    int totalNumbers(vector<int>& digit) {
        unordered_set<int>st;
        int n = digit.size();
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j || i==k|| j==k)  continue;
            if(digit[i]==0) continue;
                
                if(digit[k]%2!=0)
                        continue;
                int num = digit[i]*100+digit[j]*10+digit[k];
                st.insert(num);
            }
          }
        }
        return st.size();
    }
};