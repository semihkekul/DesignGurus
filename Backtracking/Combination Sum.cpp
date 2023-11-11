#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    vector<vector<int>> res;

    vector<int> comb;
    backTracker(candidates, target, 0, 0, comb, res);
    
    
    return res;
  }


  void backTracker(vector<int> &candidates, int target, int index, int currentSum, vector<int>& comb, vector<vector<int>>& result)
  {
      if(index >= candidates.size()) 
      {
        return;
      }

      if(currentSum == target)
      {
        result.push_back(comb);
        return;
      }

      if(currentSum > target)
      {
        return;
      }
      
      for(int i = index; i < candidates.size(); ++i)
      {
        int sum = currentSum + candidates[i];
        comb.push_back(candidates[i]);
        backTracker(candidates, target, i, sum, comb, result);
        comb.pop_back();
      }
      
  }

};

int main()
{
  Solution s;
  // Test case 1
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  auto res = s.combinationSum(candidates, target);
  for (auto r : res)
  {
    for (auto i : r)
      cout << i << " ";
    cout << endl;
  }
  // expected output: [[2, 2, 3], [7]]

  // Test case 2
  candidates = {2, 3, 5};
  target = 8;
  res = s.combinationSum(candidates, target);
  for (auto r : res)
  {
    for (auto i : r)
      cout << i << " ";
    cout << endl;
  }
  // expected output: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]

  // Test case 3
  candidates = {};
  target = 8;
  res = s.combinationSum(candidates, target);
  for (auto r : res)
  {
    for (auto i : r)
      cout << i << " ";
    cout << endl;
  }
  // expected output: []

  // Test case 4
  candidates = {5, 10, 15};
  target = 20;
  res = s.combinationSum(candidates, target);
  for (auto r : res)
  {
    for (auto i : r)
      cout << i << " ";
    cout << endl;
  }
  // expected output: [[5,5,5,5], [5,5,10], [5,15], [10,10]]

  // Test case 5
  candidates = {2, 4, 6, 8};
  target = 10;
  res = s.combinationSum(candidates, target);
  for (auto r : res)
  {
    for (auto i : r)
      cout << i << " ";
    cout << endl;
  }
  // expected output: [[2,2,2,2,2], [2,2,2,4], [2,2,6], [2,4,4], [2,8], [4,6]]

  // Test case 6
  candidates = {2, 3, 5};
  target = 0;
  res = s.combinationSum(candidates, target);
  for (auto r : res)
  {
    for (auto i : r)
      cout << i << " ";
    cout << endl;
  }
  // expected output: []
}
