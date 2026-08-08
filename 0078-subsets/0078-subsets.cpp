class Solution {
public:
    void getallSubsets(vector<int>& nums, vector<int>& ans, int i,
                       vector<vector<int>>& allSubsets) {
        
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // Include nums[i]
        ans.push_back(nums[i]);
        getallSubsets(nums, ans, i + 1, allSubsets);

        // Exclude nums[i]
        ans.pop_back();
        getallSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getallSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};