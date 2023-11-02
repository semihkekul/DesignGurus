using namespace std;

#include <iostream>
#include <vector>

class NumOfIslandsDFS
{
public:
static void rec(vector<vector<int>> &M, int i, int j)
  {
    if(i <= -1 || j <= -1 || i >= M.size() || j >= M[0].size()) return;

    if(M[i][j] == 1)
    {
      M[i][j] = -1;
      rec(M, i - 1, j) ; rec(M, i + 1, j);
      rec(M, i , j - 1) ; rec(M, i , j + 1);
    }
  }

  static int countIslands(vector<vector<int>> &M)
  {
    int totalIslands = 0;
    for(int i = 0; i < M.size(); i++)
    {
      for(int j = 0; j < M[0].size(); ++j)
      {
        if(M[i][j] == 1)
        {
          rec(M, i , j);
          totalIslands++;
        }
      }
    }
    return totalIslands;
  }
};

int main(int argc, char **argv)
{
    vector<vector<int>> vec = {
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    cout << NumOfIslandsDFS::countIslands(vec) << endl;

    vec = vector<vector<int>>{
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}};
    cout << NumOfIslandsDFS::countIslands(vec) << endl;

    return 0;
};
