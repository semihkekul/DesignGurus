using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
public:
  static int search(const vector<int>& arr, int key) {
        int i = 0;
        int j = arr.size() - 1;
        if(arr.front() < arr.back()) { //ascending
            while(i <= j) {
                int m = ceil(i / 2.0 + j / 2.0);
                if(arr[m] == key){
                    return m;
                }
                else if(arr[m] > key){
                    j = m-1;
                }
                else{
                    i = m+1;
                }
            }        
        }
        else
        {
            while(i <= j) {
                int m = ceil(i / 2.0 + j / 2.0);
                if(arr[m] == key){
                    return m;
                }
                else if(arr[m] > key){
                    i = m+1;
                }
                else{
                    j = m-1;
                }
            }
        }

        return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4, 2}, 6) << endl;
  cout << BinarySearch::search(vector<int>{1, 1, 1, 1,1}, 1) << endl;
  cout << BinarySearch::search(vector<int>{1, 1, 1, 1,1}, 2) << endl;
}
