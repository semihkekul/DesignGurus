#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;
class TripletSumCloseToTarget {
public:

    static int searchTriplet(vector<int>& arr, int targetSum) {

        int n = arr.size() - 1;

        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        int minSum = INT_MAX;
        for(int a = 0; a <= n; ++a)
        {
            //duplicates
            while(a > 0 && a <= n && arr[a] == arr[a-1])
            {
                a++;
            }
            if (a > n) break;

            

            int i = a + 1;
            int j = n;

            while(i < j)
            {
                int sum = arr[i] + arr[j] + arr[a];

                int diff = abs(targetSum - sum);

                if (diff == 0)
                {
                    return sum; // found exact triplet
                }

                if(diff == minDiff && sum < minSum)
                {
                    minSum = sum;
                }
                else if(diff < minDiff)
                {
                    minDiff = diff;
                    minSum = sum;
                }

                if(sum > targetSum)
                {
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }

        return minSum;
    }
};

int main(int argc, char* argv[]) {
    vector<int> vec = { -1, 0, 2, 3 };
    cout << TripletSumCloseToTarget::searchTriplet(vec, 3) << endl;
    vec = { -3, -1, 1, 2 };
    cout << TripletSumCloseToTarget::searchTriplet(vec, 1) << endl;
    vec = { 1, 0, 1, 1 };
    cout << TripletSumCloseToTarget::searchTriplet(vec, 100) << endl;
    vec = { 0, 0, 1, 1, 2, 6 };
    cout << TripletSumCloseToTarget::searchTriplet(vec, 5) << endl;
    vec = { -1, 0, 1, 2, 4 };
    cout << TripletSumCloseToTarget::searchTriplet(vec, 4) << endl;
}
