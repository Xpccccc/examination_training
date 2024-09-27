class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash; // 存值和对应索引
        vector<int> ret;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i]; // 计算差值
            if (hash.find(complement) != hash.end()) {
                // 有差值
                ret.push_back(hash[complement]);
                ret.push_back(i);
                return ret;
            }

            // 没有差值，把当前元素放到hash
            hash[nums[i]] = i;
        }
        return ret;
    }
};