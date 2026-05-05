class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        
        while(l < r) {
            int mid = (l + r) / 2;
            
            if(nums[mid] > nums[r]) 
                l = mid + 1;   // min is on right
            else 
                r = mid;       // min is on left (including mid)
        }
        
        return nums[l];
    }
};