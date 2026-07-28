class Solution {
public:
    string smallestPalindrome(string s) {

        int n = s.size();

        vector<int> freq(26,0);

        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }

        string left = "";
        string mid = "";

        for(int i = 0; i < 26; i++){

            if(freq[i] % 2 == 1){
                mid = char('a' + i);
            }

            int pairs = freq[i] / 2;

            while(pairs--){
                left += char('a' + i);
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};