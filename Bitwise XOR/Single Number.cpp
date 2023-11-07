using namespace std;

#include <iostream>
#include <vector>

class Solution {
  public:
    static int findSingleNumber(const vector<int>& arr) {
      int num = 0;
      for(const auto a : arr)
      {
        num = num ^ a;
      }
      return num;
    }
};
