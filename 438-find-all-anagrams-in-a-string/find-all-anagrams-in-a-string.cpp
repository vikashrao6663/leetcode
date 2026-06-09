class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> ans;

        if(m > n) return ans;

        int freq1[26] = {0};
        int freq2[26] = {0};

        for(int i = 0; i < m; i++) {
            freq1[p[i] - 'a']++;
            freq2[s[i] - 'a']++;
        }

        if(equal(freq1, freq1 + 26, freq2))
            ans.push_back(0);

        for(int i = m; i < n; i++) {
            freq2[s[i] - 'a']++;
            freq2[s[i - m] - 'a']--;

            if(equal(freq1, freq1 + 26, freq2))
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};