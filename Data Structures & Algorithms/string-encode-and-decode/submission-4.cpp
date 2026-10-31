class Solution {
public:

    string encode(vector<string>& strs) {
         if (strs.empty()) {
            return "IM SO EMPTY WAHHH";
        }

        string sol = "";

        for (string s : strs) {
            sol = sol + s;
            sol += "poyo";
        }

        return sol.substr(0, sol.size() - 4);
    }

    vector<string> decode(string s) {
        if (s == "IM SO EMPTY WAHHH") {
            return {};
        }

        vector<string> decoded_string;

        while (s.contains("poyo")) {
            int ind = s.find("poyo");
            string temp = s.substr(0, ind);
            s = s.substr(ind + 4);
            decoded_string.push_back(temp);
        }

        decoded_string.push_back(s);
        return decoded_string;

    }
};
