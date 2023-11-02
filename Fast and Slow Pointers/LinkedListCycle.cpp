using namespace std;

#include <iostream>

class ListNode {
public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class LinkedListCycle {
public:
  static bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = slow->next;
    
    while(fast != nullptr)
    {
        fast = fast->next;
        if(slow != nullptr && slow == fast) 
        {
            return true;
        }

        slow = slow->next;
        if(fast != nullptr)
        {
            fast = fast->next;
        }
        else return false;
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

  head->next->next->next->next->next->next = head->next->next;
  cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

  head->next->next->next->next->next->next = head->next->next->next;
  cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;
}
