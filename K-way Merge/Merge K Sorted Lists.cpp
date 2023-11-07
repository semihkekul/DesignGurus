using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ListNode {
public:
    int value = 0;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class MergeKSortedLists {
public:
    static ListNode* merge(const vector<ListNode*>& lists) {
        ListNode* resultHead = nullptr;

        struct CustomLess
        {
            bool operator()(const ListNode* l, const ListNode* r) const { return l->value > r->value; }
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, CustomLess> MinHeap;

        for(const auto lN: lists)
        {
            MinHeap.push(lN);
        }

        resultHead = MinHeap.top();
        ListNode* traverser = resultHead;
        
        if(MinHeap.top()->next != nullptr)
          {
              MinHeap.push(MinHeap.top()->next);
          }
        MinHeap.pop();

        while(!MinHeap.empty())
        {

            traverser->next = MinHeap.top();
            traverser = traverser->next;
            if(MinHeap.top()->next != nullptr)
            {
                MinHeap.push(MinHeap.top()->next);
            }
            MinHeap.pop();
        }
        
        return resultHead;
    }
};

int main(int argc, char* argv[]) {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(6);
    l1->next->next = new ListNode(8);

    ListNode* l2 = new ListNode(3);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(7);

    ListNode* l3 = new ListNode(1);
    l3->next = new ListNode(3);
    l3->next->next = new ListNode(4);

    ListNode* result = MergeKSortedLists::merge(vector<ListNode*>{l1, l2, l3});
    cout << "Here are the elements form the merged list: ";
    while (result != nullptr) {
        cout << result->value << " ";
        result = result->next;
    }
}
