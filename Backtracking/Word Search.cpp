#include <iostream>
#include <vector>
using namespace std;

bool backtracker(vector<vector<char>> &board,
                 vector<vector<bool>> &visited,
                 string &word, int r, int c, int index)
{

    if (index == word.size())
    {
        return true;
    }

    if (r >= board.size() || r < 0 || c >= board[0].size() || c < 0)
    {
        return false;
    }

    if (visited[r][c])
        return false;

    char ch = board[r][c];

    if (ch == word[index])
    {
        visited[r][c] = true;
        bool left = backtracker(board, visited, word, r, c - 1, index + 1);
        bool right = backtracker(board, visited, word, r, c + 1, index + 1);
        bool up = backtracker(board, visited, word, r - 1, c, index + 1);
        bool down = backtracker(board, visited, word, r + 1, c, index + 1);
        if (up || down || left || right)
        {
            return true;
        }
        visited[r][c] = false;
        return false;
    }
    else
    {
        return false;
    }
}

bool exist(vector<vector<char>> &board, string word)
{

    int r = 0, index = 0;
    for (; r < board.size(); ++r)
    {
        index = 0;
        for (int c = 0; c < board[0].size(); ++c)
        {
            vector<vector<bool>> visited(board.size(),
                                         vector<bool>(board[0].size(), false));

            if (backtracker(board, visited, word, r, c, index))
                return true;
        }
    }
    return false;
}


int main() {
    // Test Case 1
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << exist(board, word) << endl; // expected output: 1

    // Test Case 2
    board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    word = "SEE";
    cout << exist(board, word) << endl; // expected output: 1

    // Test Case 3
    board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    word = "ABCB";
    cout << exist(board, word) << endl; // expected output: 0

    // Test Case 4
    board = {{'a','a'}};
    word = "aaa";
    cout << exist(board, word) << endl; // expected output: 0

    // Test Case 5
    board = {{'a'}};
    word = "a";
    cout << exist(board, word) << endl; // expected output: 1

    board = {
        {'a','b','c','d','e'},
        {'f','g','h','i','j'},
        {'k','l','m','n','o'},
        {'p','q','r','s','t'},
        {'u','v','w','x','y'},
        {'z','a','b','c','d'}
    };
    word = "abcde";
    cout << exist(board, word) << endl; // expected output: 1

    // Test Case 7
    board = {
        {'a','b','c','d','e'},
        {'f','g','h','i','j'},
        {'k','l','m','n','o'},
        {'p','q','r','s','t'},
        {'u','v','w','x','y'},
        {'z','a','b','c','d'}
    };
    word = "zabcd";
    cout << exist(board, word) << endl; // expected output: 1
}
