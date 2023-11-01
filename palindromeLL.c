/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow =head;
        ListNode* fast =head;
        ListNode*temp=nullptr;
        int count=0;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        temp=slow->next;
        if(fast->next!=nullptr){
            fast=fast->next;
        }
        //reverse from temp to fast
        while(){
            slow->next=
        }
    }
};
