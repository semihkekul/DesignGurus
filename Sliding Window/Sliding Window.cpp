using namespace std;

#include <iostream>
#include <vector>

class AverageOfSubarrayOfSizeK
{
public:
    static vector<double> findAverages(double K, const vector<int> &arr)
    {
        vector<double> avarages;
        int i = 0;
        int j = K-1;

        int sum = 0;

        for(int k = 0; k < K; ++k)
        {
            sum += arr[k];
        }

        avarages.push_back(sum / K);

        for( int i = 0, j = K; j < arr.size(); i++, j++)
        {
            sum -= arr[i];
            sum += arr[j];    
            avarages.push_back(sum / K);
        }
        return avarages;
    }
};

int main(int argc, char *argv[])
{
    vector<double> result =
        AverageOfSubarrayOfSizeK::findAverages(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
    cout << "Averages of subarrays of size K: ";
    for (double d : result)
    {
        cout << d << " ";
    }
    cout << endl;
}
