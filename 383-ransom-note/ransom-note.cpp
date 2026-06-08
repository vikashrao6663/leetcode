class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int n = ransomNote.size();
        int m = magazine.size();
        int freq[26]={0};
        for(int i = 0;i<m;i++){
            freq[magazine[i]-'a']++;
        }
        for(int j=0;j<n;j++){
           freq[ransomNote[j] - 'a']--;
        
        if(freq[ransomNote[j]-'a']< 0)
       return false;
    }
    return true;
    }
};