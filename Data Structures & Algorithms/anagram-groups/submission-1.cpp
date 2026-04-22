class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (string s: strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(s);
        }
        vector<vector<string>> res;
        for (auto [x, y]: mp) {
            res.push_back(y);
        }
        return res;
    }
};