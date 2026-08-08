class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        backtrack(0, nums, current, ans);

        return ans;
    }

    void backtrack(int start, vector<int>& nums,
                   vector<int>& current,
                   vector<vector<int>>& ans) {
        
        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);

            backtrack(i + 1, nums, current, ans);

            current.pop_back();
        }
    }
};