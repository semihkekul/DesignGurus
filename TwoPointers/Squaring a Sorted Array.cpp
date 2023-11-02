using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
public:
  static vector<int> makeSquares(const vector<int>& arr) {
 int n = arr.size();
    vector<int> squares(n);
    int i = 0;
    int j = arr.size() - 1;
    int k = arr.size() - 1;
    while(i <= j)
    {
       int sqi = arr[i] * arr[i];
       int sqj = arr[j] * arr[j];
       if(sqi>sqj)
       {
          squares[k] = sqi;
          i++;
       }
       else 
       {
          squares[k] = sqj;
          j--;
       }
       k--;
    }
    return squares;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = SortedArraySquares::makeSquares(vector<int>{-2, -1, 0, 2, 3});
  for (auto num : result) {
      cout << num << " ";
  }
  cout << endl;

  result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
  for (auto num : result) {
      cout << num << " ";
  }
  cout << endl;
}
