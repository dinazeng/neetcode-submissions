class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.length();
        int size2= s2.length();
        if (size1 + size2 != s3.length()) return false;

        vector<vector<bool>> can (size1 + 1, vector<bool> (size2 + 1));
        
        can[size1][size2] = true;

        for (int i = size1; i >= 0; i--) {
            for (int j = size2; j >= 0; j--) {
                if (i < size1 && s3[i + j] == s1[i] && can[i + 1][j]) {
                    can[i][j] = true;
                }

                if (j < size2 && s3[i + j] == s2[j] && can[i][j + 1]) {
                    can[i][j] = true;
                }
            }
        }

        return can[0][0];
    }
};
