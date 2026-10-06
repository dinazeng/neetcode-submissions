class Solution {
public:
    string decodeString(string s) {
        vector<string> stringStack;
        vector<int> countStack;
        string curr = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                stringStack.push_back(curr);
                countStack.push_back(k);

                curr = "";
                k = 0;
            } else if (c == ']') {
                string temp = curr;
                curr = stringStack.back();
                stringStack.pop_back();
                int count = countStack.back();
                countStack.pop_back();

                for (int i = 0; i < count; i++) {
                    curr += temp;
                }

            } else {
                curr += c;
            }
        }

        return curr;
    }
};