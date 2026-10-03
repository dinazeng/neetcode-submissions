class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int x : hand) freq[x]++;

        while (!freq.empty()) {
            int start = freq.begin()->first;
            for (int card = start; card < start + groupSize; card++) {
                auto it = freq.find(card);
                if (it == freq.end()) return false;
                if (--(it->second) == 0) freq.erase(it);
            }
        }
        return true;
    }
};
