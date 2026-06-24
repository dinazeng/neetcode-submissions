class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Size = s1.length();
        int s2Size = s2.length();

        if (s1Size > s2Size) {
            return false;
        }

        unordered_map <char, int> s1Mapped;

        for (int i = 0; i < s1Size; i++) {
            s1Mapped[s1[i]]++;
        }

        unordered_map<char, int> s2Mapped;
        for (int i = 0; i < s1Size; i++) {
            s2Mapped[s2[i]]++;
        }
        

        for (int i = s1Size; i < s2Size; i++) {
            if (s2Mapped == s1Mapped){
                return true;
            } else {
                char removing = s2[i - s1Size];
                s2Mapped[removing]--;
                s2Mapped[s2[i]]++;

                if (s2Mapped[removing] <= 0) {
                    s2Mapped.erase(removing);
                }
            }
        }

        return s2Mapped == s1Mapped;
    }
};
