class Solution {
public:
    void subset_2(vector<int> &nums, vector<int> &res, vector<vector<int>> &result,
              int index, int sum,int resultsum,int k) {
  if (sum == resultsum && res.size() == k) {
    result.push_back(res);
  }

  if (index >= nums.size()) {
    return;
  }

  for (int i = index; i < nums.size(); i++) {
    if (i > index && nums[i] == nums[i - 1])
      continue;

    int num = nums[i];
    res.push_back(num);
    subset_2(nums, res, result, i + 1, sum + num,resultsum,k);
    res.pop_back();
  }
}

    vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> res;
  vector<vector<int>> result;
  subset_2(nums, res, result, 0, 0,n,k);
  return result;
        
    }
};