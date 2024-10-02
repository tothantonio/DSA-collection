#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution{
public:
    ListNode* insertionSortList(ListNode* head){
        if(!head) return nullptr;

        vector<int> nums;
        ListNode* current = head;

        while(current){
            nums.push_back(current->val);
            current = current->next;
        }

        for(int i = 0; i < nums.size(); i++){
            int currVal = nums[i];
            int j = i - 1;
            while(j >= 0 && nums[j] > currVal){
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = currVal;
        }
        current = head;
        for(int i = 0; i < nums.size(); i++){
            current->val = nums[i];
            current = current->next;
        }
        return head;
    }
};
    //T_atribuition(n) = O(n)
    //T_compare(n) = O(n^2)
    //Stabile: Yes
    //Time: O(n^2)
    //Space: O(n)

int main(){

    Solution s;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ListNode* ans = s.insertionSortList(head);

    while(ans){
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}