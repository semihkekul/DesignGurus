using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
public:
  static int remove(vector<int> &arr) {
    int i = 0;
    int j = 1;
    while(j <= arr.size() -1)
    {
       if(arr[i] != arr[j])
       {
          arr[i+1] = arr[j];
          i++;
       } 
       j++;
    }
    return i+1;
  }
};

int main(int argc, char* argv[]) {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;

  arr = vector<int>{2, 2, 2, 11};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;
}