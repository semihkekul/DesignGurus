#include <iostream>
#include <vector>

using namespace std;

const int N = 9;
bool isValid(int r, int c, int num, vector<vector<char>> &board)
{
    for (int i = 0; i < N; ++i)
    {
        if (board[i][c] == char(num + '0'))
        {
            return false;
        }

        if (board[r][i] == char(num + '0'))
        {
            return false;
        }
    }

    int rStart = 0;
    int cStart = 0;

    if (r >= 6)
    {
        rStart = 6;
    }
    else if (r >= 3)
    {
        rStart = 3;
    }

    if (c >= 6)
    {
        cStart = 6;
    }
    else if (c >= 3)
    {
        cStart = 3;
    }

    for (int i = rStart; i < rStart + 3; ++i)
    {
        for (int j = cStart; j < cStart + 3; ++j)
        {
            if (board[i][j] == char(num + '0'))
            {
                return false;
            }
        }
    }

    return true;
}

pair<int, int> nextEmpty(int i, int j, vector<vector<char>> &board)
{
    j++;
    for (; i < N; ++i)
    {
        for (; j < N; j++)
        {
            if (board[i][j] == '.')
            {
                return {i, j};
            }
        }
        j = 0;
    }

    return {-1, -1};
}

void boardPrt(vector<vector<char>> &board)
{
    cout <<"=================\n"; 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool solver(int i, int j, vector<vector<char>> &board)
{

    for (int k = 1; k < 10; ++k)
    {
        if (isValid(i, j, k, board))
        {
            board[i][j] = k + '0';
            const auto i_j = nextEmpty(i, j, board);
            if (i_j.first == -1 && i_j.second == -1)
            {
                return true;
            }

            if (!solver(i_j.first, i_j.second, board))
            {
                board[i][j] = '.';
                continue;
            }
            return true;
        }
        else
        {
            continue;
        }
    }

    board[i][j] = '.';
    return false;
}

bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == '.')
            {
                return solver(i, j, board);
            }
        }
    }
    return false;
}
int main()
{

    // Test case 1
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (solveSudoku(board))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists";
    }
    cout << endl;
    /* expected output:
      5 3 4 6 7 8 9 1 2
      6 7 2 1 9 5 3 4 8
      1 9 8 3 4 2 5 6 7
      8 5 9 7 6 1 4 2 3
      4 2 6 8 5 3 7 9 1
      7 1 3 9 2 4 8 5 6
      9 6 1 5 3 7 2 8 4
      2 8 7 4 1 9 6 3 5
      3 4 5 2 8 6 1 7 9
    */

    //   // Test case 2
    //   board = {
    //       {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
    //       {'.', '.', '3', '6', '.', '.', '.', '.', '.'},
    //       {'.', '7', '.', '.', '9', '.', '2', '.', '.'},
    //       {'.', '5', '.', '.', '.', '7', '.', '.', '.'},
    //       {'.', '.', '.', '.', '4', '5', '7', '.', '.'},
    //       {'.', '.', '.', '1', '.', '.', '.', '3', '.'},
    //       {'.', '.', '1', '.', '.', '.', '.', '6', '8'},
    //       {'.', '.', '8', '5', '.', '.', '.', '1', '.'},
    //       {'.', '9', '.', '.', '.', '.', '4', '.', '.'}};
    //   if (solveSudoku(board))
    //   {
    //     for (int i = 0; i < N; i++)
    //     {
    //       for (int j = 0; j < N; j++)
    //       {
    //         cout << board[i][j] << " ";
    //       }
    //       cout << endl;
    //     }
    //   }
    //   else
    //   {
    //     cout << "No solution exists";
    //   }
    //   /* expected output:
    //     8 1 2 7 5 3 6 4 9
    //     9 4 3 6 8 2 1 7 5
    //     6 7 5 4 9 1 2 8 3
    //     1 5 4 2 3 7 8 9 6
    //     3 6 9 8 4 5 7 2 1
    //     2 8 7 1 6 9 5 3 4
    //     5 2 1 9 7 4 3 6 8
    //     4 3 8 5 2 6 9 1 7
    //     7 9 6 3 1 8 4 5 2
    // */
}