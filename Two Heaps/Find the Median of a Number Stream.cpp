using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
public:
  priority_queue<int> maxHeap; 
  priority_queue<int, vector<int>, greater<int>> minHeap;

  virtual void insertNum(int num) {
    if (maxHeap.empty() && minHeap.empty())
    {
        maxHeap.push(num);
    }
    else
    {
        if(num < maxHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        if(maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

  }

  virtual double findMedian() {
    if(maxHeap.size() == minHeap.size()){
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    else{
        return maxHeap.top();
    }    
  }
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}
