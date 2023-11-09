class Solution {
  public:

    void recursion(vector<int> &profits, vector<int> &weights, 
                  int index, 
                  int capacityLeft,
                  int profitSum,
                  int &maxProfit,
                  vector<vector<int>>& DP) {
      string padding(index, '-');              
      std::cout <<padding<<"index: " <<index << " capLeft: " << capacityLeft << " p.Sum: " <<
              profitSum << " maxProfit: " << maxProfit << "\n";             
      if(index >= profits.size()) 
      {
        return;
      } 
    
      int w = weights[index];
      int p = profits[index];

     


      if(DP[index][capacityLeft] != -1)
      {
        std::cout << "found " << DP[index][capacityLeft - w] << "\n";
        return;
      }

      if(capacityLeft - w >= 0 )
      {


        maxProfit = max(maxProfit, profitSum + p);
        recursion(profits, weights, index + 1, 
                              capacityLeft - w, profitSum + p, maxProfit, DP);

        

      }
      
      recursion(profits, weights, index + 1, 
                            capacityLeft, profitSum, maxProfit, DP);
      
      DP[index][capacityLeft] = maxProfit;
    }


    int solveKnapsack(vector<int> &profits, vector<int> &weights, int capacity) {
      int maxProfit = 0;
      vector<vector<int>> DP(profits.size(), vector<int>(capacity + 1, -1));
      std::cout <<"\n";
      recursion(profits, weights, 0, 
                            capacity, 0, maxProfit, DP);
 
      return maxProfit;
    }
  };
