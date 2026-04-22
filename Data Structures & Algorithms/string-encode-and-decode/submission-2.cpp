class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";
        for (auto& str : strs) {
            ans += to_string(str.size()) + '#' + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            string current = s.substr(j + 1, len);
            ans.push_back(current);
            i = j + len + 1;
        }
        return ans;
    }
};



