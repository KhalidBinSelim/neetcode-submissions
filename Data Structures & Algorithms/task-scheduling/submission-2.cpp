class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task: tasks) cnt[task - 'A']++;
        sort(cnt.begin(), cnt.end());
        int max_freq = cnt[25];
        int idle_cnt = (max_freq - 1) * n;
        for (int i = 24; i >= 0; i--) idle_cnt -= min(max_freq - 1, cnt[i]);
        return max(0, idle_cnt) + tasks.size();
    }
};
