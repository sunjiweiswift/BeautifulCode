class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int pos = paratiton(left, right, nums);
        k--;
        while (k != pos) {
            if (k > pos) {
                left = pos + 1;
            } else {
                right = pos - 1;
            }
            pos = paratiton(left, right, nums);
        }
        return nums[pos];
    }

private:
    int paratiton(int left, int right, vector<int>& nums) {
        int base = nums[left];
        int i = left;
        int j = right;
        while (i < j) {
            while (base >= nums[j] && i < j) {
                j--;
            }
            while (base <= nums[i] && i < j) {
                i++;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[left], nums[i]);
        return i;
    }
};
