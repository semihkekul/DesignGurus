using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MergeIntervals {
public:
  static vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() < 2) {
      return intervals;
    }

    sort(intervals.begin(), intervals.end(),
        [](const Interval &x, const Interval &y) { return x.start < y.start; });

    vector<Interval> mergedIntervals;
    mergedIntervals.push_back(*intervals.begin());

    auto iter = intervals.begin();
    iter++;

    for(; iter != intervals.end(); iter++)
    {
        auto& last = mergedIntervals.back();
        if(iter->start <=  last.end)
        {
            last.end = max(last.end, iter->end);
        }
        else
        {
            mergedIntervals.push_back(*iter);
        }
    }

    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}
