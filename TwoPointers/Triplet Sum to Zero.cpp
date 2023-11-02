using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> triplets;

    for(int k = 0; k < arr.size() - 1; ++k)
    {
        findTheOthers(k, arr, triplets);
    }

    return triplets;
  }

  static void findTheOthers(int k, vector<int> &arr, vector<vector<int>>& triplets) //indices
  {
        int i = k + 1;
        int j = arr.size() - 1 ;

        int val = -arr[k];
        while(i < j)
        {
            int sum = arr[i] + arr[j];

            if(sum == val)
            {
                triplets.push_back({arr[k],arr[i],arr[j]});
                i++;
                j--;
            }
            else if (sum < val)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-3, 0, 1, 2, -1, 1, -2};
  auto result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {-5, 2, -1, -2, 3};
  result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
