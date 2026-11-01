class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size_1 = s1.size();
        int size_2 = s2.size();

        if (size_2 < size_1) {
            return false;
        }

        map <char, int> freq_s1;
        map <char, int> freq_s2;

        for (char c : s1) {
            freq_s1[c]++;
        }

        for (int i = 0; i < size_1; i++) {
            freq_s2[s2[i]]++;
        }

        if (freq_s2 == freq_s1) {
            return true;
        }

        for (int i = size_1; i < size_2; i++) {
            char remove = s2[i - size_1];
            freq_s2[remove]--;
            if (freq_s2[remove] == 0) {
                freq_s2.erase(remove);
            }

            freq_s2[s2[i]]++;

             if (freq_s2 == freq_s1) {
                return true;
            }
        }
        
        return false;
    }
};
