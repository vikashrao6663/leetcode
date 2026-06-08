class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int n = ransomNote.size();
        int m = magazine.size();

        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());

        for(int i = 0; i < n; i++) {

            int j;

            for(j = 0; j < m; j++) {

                if(ransomNote[i] == magazine[j]) {
                    magazine[j] = '#';
                    break;
                }
            }

            if(j == m)
                return false;
        }

        return true;
    }
};