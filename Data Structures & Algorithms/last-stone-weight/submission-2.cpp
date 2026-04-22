class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        pq.push(stones[0]);
        if (stones.size() == 1) return stones[0];
        for (int i = 1; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        while (pq.size() > 1) {
            int max_w = pq.top();
            pq.pop();
            int second_max_w = pq.top();
            pq.pop();
            if (max_w > second_max_w) pq.push(max_w - second_max_w);
        }
        pq.push(0);
        return pq.top();
    }
};
