class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task: tasks) cnt[task - 'A']++;
        priority_queue<int> max_heap;
        for (int x: cnt) if (x > 0) max_heap.push(x);
        int time = 0;
        queue<pair<int, int>> q;
        while (!max_heap.empty() or !q.empty()) {
            time++;
            if (max_heap.empty()) {
                time = q.front().second;
            } else {
                int cnt = max_heap.top() - 1;
                max_heap.pop();
                if (cnt > 0) q.push({cnt, time + n});
            }
            if (!q.empty() and q.front().second == time) {
                max_heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
