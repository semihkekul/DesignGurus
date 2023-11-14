using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

struct Vertex{
  int value;
  int incomingsCount;
  vector<int> Outgoings;
};

class TopologicalSort {
public:
 static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
    vector<int> result;
    
    vector<Vertex> Graph(vertices);
    for(int i = 0; i < vertices; ++i)
    {
      Graph[i].value = i;
      Graph[i].incomingsCount = 0;
    }

    for(int i = 0; i < edges.size(); ++i)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        Graph[from].Outgoings.push_back(to);
        Graph[to].incomingsCount++;
    }

    queue<Vertex> BFQue; 

    for(auto& vertex : Graph) 
    {
      if(vertex.incomingsCount == 0)
      {
        BFQue.push(vertex);
      }
    }

    while(!BFQue.empty())
    {
      int qSize = BFQue.size();

      for(int i = 0; i < qSize ; ++i)
      {
        auto qVertex = BFQue.front();
        result.push_back(qVertex.value);

        for(int o = 0 ; o < qVertex.Outgoings.size(); ++o)
        {
            if(--Graph[qVertex.Outgoings[o]].incomingsCount == 0)
            {
              BFQue.push(Graph[qVertex.Outgoings[o]]);
            }
        }
        BFQue.pop();
      }
    }

  
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result =
      TopologicalSort::sort(4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0},
                                                  vector<int>{2, 0}, vector<int>{2, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

//   result = TopologicalSort::sort(
//       5, vector<vector<int>>{vector<int>{4, 2}, vector<int>{4, 3}, vector<int>{2, 0},
//                             vector<int>{2, 1}, vector<int>{3, 1}});
//   for (auto num : result) {
//     cout << num << " ";
//   }
//   cout << endl;

//   result = TopologicalSort::sort(
//       7, vector<vector<int>>{vector<int>{6, 4}, vector<int>{6, 2}, vector<int>{5, 3},
//                             vector<int>{5, 4}, vector<int>{3, 0}, vector<int>{3, 1},
//                             vector<int>{3, 2}, vector<int>{4, 1}});
//   for (auto num : result) {
//     cout << num << " ";
//   }
//   cout << endl;
}
