class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        string ans = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1')
                ones++;

            // Keep at most k ones
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // Remove useless leading zeros
            while (ones == k && s[left] == '0')
                left++;

            // Update answer
            if (ones == k) {
                string cur = s.substr(left, right - left + 1);

                if (ans.empty() ||
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans)) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};