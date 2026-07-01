class Solution {
public:
    int characterReplacement(string s, int k) {
    vector<int> freq(26,0);
    int i =0;
    int j =0;
    int ans = 0;
    int maxf = 0;
    while(j<s.size()){
        freq[s[j]-'A']++;
        maxf = max(maxf,freq[s[j]-'A']);
     while((j-i+1)-maxf > k){
        freq[s[i]-'A']--;
        i++;
     } 
     ans=max(ans,j-i+1);  
     j++;
    }
    return ans;
    }
};