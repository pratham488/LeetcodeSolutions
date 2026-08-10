#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(int start_index, int target, const std::vector<int>& candidates, 
                   std::vector<int>& current_path, std::vector<std::vector<int>>& result) {
        
        // Base case: If the target is met, add the current combination to the result
        if (target == 0) {
            result.push_back(current_path);
            return;
        }

        for (int i = start_index; i < candidates.size(); ++i) {
            // Pruning Step 1: Skip duplicates at the same level of the recursion tree
            // to avoid generating duplicate combinations.
            if (i > start_index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Pruning Step 2: Since the array is sorted, if the current element 
            // is greater than the target, all subsequent elements will also be too large.
            if (candidates[i] > target) {
                break;
            }

            // Include the current element
            current_path.push_back(candidates[i]);
            
            // Recurse with updated target. 
            // We pass i + 1 because each number can only be used once.
            backtrack(i + 1, target - candidates[i], candidates, current_path, result);
            
            // Backtrack: Remove the element to explore other possibilities
            current_path.pop_back();
        }
    }

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current_path;
        
        // Sorting is crucial. It groups duplicates together and allows for early termination.
        std::sort(candidates.begin(), candidates.end());
        
        backtrack(0, target, candidates, current_path, result);
        
        return result;
    }
};