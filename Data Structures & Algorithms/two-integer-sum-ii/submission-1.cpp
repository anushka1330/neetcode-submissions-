class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int l = 0, r = num.size() - 1;
    while (num[l] + num[r] != target)
        (num[l] + num[r] < target) ? l++ : r--;
    return {l + 1, r + 1};
    }
};
