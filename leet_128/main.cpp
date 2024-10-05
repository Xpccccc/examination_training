class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> num_set(nums.begin(), nums.end());
        int ret = 0;
        for (int num : nums) {
            if (num_set.find(num - 1) == num_set.end()) {
                int cur_num = num; // 前一个数字不存在，从这个数字开始
                int cur_len = 1;
                while (num_set.find(cur_num + 1) !=
                       num_set.end()) { // 能找到后面一个数字
                    cur_num++;
                    cur_len++;
                }
                ret = max(ret, cur_len);
            }
        }
        return ret;
    }
};