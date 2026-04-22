class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> frequency;
        for (auto x: nums) {
            frequency[x]++;
        }
        int value = 0;
        for (auto &x: nums) {
            while (frequency[value] == 0 and value < 2) {
                value++;
            }
            x = value;
            frequency[value]--; 
        }
    }
};