class Solution {
public:
    vector<int> partitionLabels(string s) {
        int size = s.size();
        map<char, int> last_index;

        for (int i = 0; i < size; i++) {
            last_index[s[i]] = i;
        }

        int end = 0;
        int curr = 0;
        vector<int> partition_size;

        for (int i = 0; i < size; i++) {
            end = max(end, last_index[s[i]]);

            curr++;

            if (i == end) {
                partition_size.push_back(curr);
                curr = 0;
            }
        }

        return partition_size;
    }
};
