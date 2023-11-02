using namespace std;

#include <iostream>
#include <deque>
#include <vector>

class TreeNode {
public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class LevelOrderTraversal {
public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) {
      return result;
    }

    deque<TreeNode*> Queue;
    Queue.push_back(root);

    while(!Queue.empty())
    {
        int len = Queue.size();
        vector<int> level;
        for(int i = 0; i < len; ++i)
        {
            level.push_back(Queue.front()->val);
            if(Queue.front()->left)
            {
                Queue.push_back(Queue.front()->left);
            }

            if(Queue.front()->right)
            {
                Queue.push_back(Queue.front()->right);
            }
            Queue.pop_front();
        }
        result.push_back(level);
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
