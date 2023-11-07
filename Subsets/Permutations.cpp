using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
public:


  static void printer(const vector<int>& vec)
  {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  static vector<vector<int>> findPermutations(const vector<int>& nums) {

    vector<vector<int>> result;
    
    result.push_back({}); //empty permutaion

    for(int n = 0; n < nums.size(); ++n)
    {
        int number = nums[n];
        int rSize = result.size();
        for(int r = 0; r < rSize; ++r){
            auto res = result[r];
            int k = res.size();

            for(int i = 0; i <= k; i++){
                auto copy = res;
                auto it = copy.begin();
                copy.insert(next(it,i),number); 

                result.push_back(copy);   
            }
        }
        result.erase(result.begin(), result.begin() + rSize);

    }

    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}