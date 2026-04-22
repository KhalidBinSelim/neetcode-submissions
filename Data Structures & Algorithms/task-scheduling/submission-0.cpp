class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task: tasks) cnt[task - 'A']++;
        vector<pair<int, int>> v;
        for (int i = 0; i < 26; i++) if (cnt[i] > 0) v.emplace_back(cnt[i], i);
        int time = 0;
        vector<int> processed;
        while (!v.empty()) {
            int cur_max = -1;
            for (int i = 0; i < v.size(); i++) {
                bool ok = true;
                for (int j = max(0, time - n); j < time; j++) {
                    if (j < processed.size() and processed[j] == v[i].second) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;
                if (cur_max == -1 or v[cur_max].first < v[i].first) {
                    cur_max = i;
                }
            }
            time++;
            int cur = -1;
            if (cur_max != -1) {
                cur = v[cur_max].second;
                v[cur_max].first--;
                if (v[cur_max].first == 0) v.erase(v.begin() + cur_max);
            }
            processed.push_back(cur);
        }
        return time;
    }
};
