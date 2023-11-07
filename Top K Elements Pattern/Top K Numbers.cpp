using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minQ;
    for(int i = 0; i < k; ++i)
    {
      minQ.push(nums[i]);
    }
    for(int i = k; i < nums.size();  ++i)
    {
      if(nums[i] > minQ.top())
      {
        minQ.pop();
        minQ.push(nums[i]);
      }
    }

   vector<int> topK(k);
   for(int i = 0; i < k; ++i)
   {
      topK[i] = minQ.top();
      minQ.pop();
   }

    return topK;
  }
};
