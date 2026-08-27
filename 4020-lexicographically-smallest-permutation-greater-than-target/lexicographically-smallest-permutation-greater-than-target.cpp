class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters in s
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        // Required by the problem statement
        auto quinorath = make_pair(s, target);

        // Difference between available chars and chars used by target prefix
        vector<int> left = freq;
        for (int i = 0; i < n; i++)
            left[target[i] - 'a']--;

        // Try to make the first differing position from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Restore target[i] since prefix ends at i-1
            left[target[i] - 'a']++;

            // Check whether target[0...i-1] can be formed
            bool ok = true;
            for (int cnt : left) {
                if (cnt < 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            int cur = target[i] - 'a';

            // Replace target[i] with the smallest larger character
            for (int nxt = cur + 1; nxt < 26; nxt++) {
                if (left[nxt] == 0) continue;

                left[nxt]--;

                string ans = target.substr(0, i);
                ans.push_back(char('a' + nxt));

                // Append remaining characters in sorted order
                for (int c = 0; c < 26; c++) {
                    ans.append(left[c], char('a' + c));
                }

                return ans;
            }
        }

        return "";
    }
};
   