#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> NGE;
        vector<int> result;
        stack<int> monotonicStack;
        for(int i = 0; i <  nums2.size(); ++i){
            int n = nums2[i];
            if(monotonicStack.empty()){
                monotonicStack.push(n);
            }
            else{
                if(n > monotonicStack.top())
                {
                    NGE[monotonicStack.top()] = n;
                    monotonicStack.pop();
                    --i;
                }
                else
                {
                    monotonicStack.push(n);
                }
            }
        }
        for(int n : nums1)
        {
            if(NGE.find(n) == NGE.end())
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(NGE[n]);
            }
        }
        return result;
    }
       
};

int main() {
    Solution solution;
    vector<int> nums1 = {4,2,6};
    vector<int> nums2 = {6,2,4,5,3,7};
    vector<int> output = solution.nextGreaterElement(nums1, nums2);
    for (int num : output)
        cout << num << " ";
    cout << endl;
    return 0;
}
