class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> freq;
        for (auto num: nums) {
            freq[num]++;
        }
        for (auto num: nums) {
            if(freq.find(num) != freq.end() and freq[num] == 1) {
                return num;
            }
        }
    }
};
