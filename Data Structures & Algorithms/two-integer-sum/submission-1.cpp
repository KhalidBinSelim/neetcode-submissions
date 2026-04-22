class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_index_map;
        int length_of_nums = nums.size();
        // for (int i = 0; i < length_of_nums; i++) {
        //     value_index_map[nums[i]] = i;
        // }
        for (int i = 0; i < length_of_nums; i++) {
            int remained_value = target - nums[i];
            auto it = value_index_map.find(remained_value);
            if (it != value_index_map.end()) {
                return {value_index_map[remained_value],i};
            }
            value_index_map[nums[i]] = i;
        }
        return {};
    }
};