class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string cur = strs[i];
            sort(strs[i].begin(), strs[i].end());
            if (mp.find(strs[i]) != mp.end()) {
                mp[strs[i]].push_back(cur);
            } else {
                vector<string> v;
                v.push_back(cur);
                mp[strs[i]] = v;
            }
        }
        vector<vector<string>> ans;
        for (auto [x,y]: mp) {
            ans.push_back(y);
        }
        return ans;
    }
};