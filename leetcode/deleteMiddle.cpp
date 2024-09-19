#include <iostream>

using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* deleteMiddle(ListNode* head){
        //base case
        if(!head || !head->next){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //acum slow arata catre middle element

        prev->next = slow->next;
        free(slow);
        return head;
    }
};

void printlist(ListNode* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    Solution s;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = s.deleteMiddle(head);
    
    printlist(head);
    return 0;
}