#include <iostream>
#include <unordered_set>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
  public:
    bool checkIfPangram(string sentence) {
      unordered_set<char> S;
      std::for_each(sentence.begin(), sentence.end(), [&S, &sentence](char c){
        char l = tolower(c);
        if(l <= 'z' && l>='a') 
        {
            S.insert(l);
        }
      }) ; 
      return S.size() == 26;
    }
};

int main() {

    cout << tolower(' ') << endl;

    Solution sol;

    // Test case 1: "TheQuickBrownFoxJumpsOverTheLazyDog"
    // Expected output: true
    cout << sol.checkIfPangram("TheQuickBrownFoxJumpsOverTheLazyDog") << endl;

    // Test case 2: "This is not a pangram"
    // Expected output: false
    cout << sol.checkIfPangram("This is not a pangram") << endl;

    // Test case 3: "abcdef ghijkl mnopqr stuvwxyz"
    // Expected output: true
    cout << sol.checkIfPangram("abcdef ghijkl mnopqr stuvwxyz") << endl;

    // Test case 4: ""
    // Expected output: false
    cout << sol.checkIfPangram("") << endl;

    // Test case 5: "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    // Expected output: true
    cout << sol.checkIfPangram("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") << endl;

    return 0;
}
