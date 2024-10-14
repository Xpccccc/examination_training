class Solution {
  public:
    const int MOD = 1000000007;

    int mergeSort(vector<int>& nums, vector<int>& temp, int left, int right) {
        if (left >= right) {
            return 0;
        }

        int mid = left + (right - left) / 2;
        int inverseCount = 0;

        // 递归对左右两部分进行排序，并统计逆序对
        inverseCount += mergeSort(nums, temp, left, mid);
        inverseCount += mergeSort(nums, temp, mid + 1, right);

        // 合并两个有序数组并统计逆序对
        inverseCount += merge(nums, temp, left, mid, right);

        // 防止溢出，取模
        return inverseCount % MOD;
    }

    int merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
        int i = left;    // 左半部分的起始位置
        int j = mid + 1; // 右半部分的起始位置
        int k = left;    // 临时数组的起始位置
        int inverseCount = 0;

        // 归并两个有序数组并统计逆序对
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
                // 左半部分的i之后的元素都比nums[j]大，形成逆序对
                inverseCount += (mid - i + 1);
                inverseCount %= MOD; // 保持取模操作
            }
        }

        // 复制剩余的左半部分
        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        // 复制剩余的右半部分
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        // 将排好序的部分复制回原数组
        for (int i = left; i <= right; ++i) {
            nums[i] = temp[i];
        }

        return inverseCount;
    }

    int InversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> temp(n); // 用于存放排序的临时数组
        return mergeSort(nums, temp, 0, n - 1);
    }
};
