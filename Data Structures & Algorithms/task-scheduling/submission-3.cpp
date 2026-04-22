class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task: tasks) cnt[task - 'A']++;
        int max_freq = *max_element(cnt.begin(), cnt.end());
        int max_cnt = 0;
        for (int i: cnt) if (i == max_freq) max_cnt++;
        int time = (max_freq - 1) * (n + 1) + max_cnt;
        return max((int)tasks.size(), time);
    }
};
