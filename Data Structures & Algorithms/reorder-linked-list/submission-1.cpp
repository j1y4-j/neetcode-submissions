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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || !head->next->next) return;
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=(fast->next)->next;
        }
        // when fast reaches end, slow is mid
        ListNode* second=slow->next;
        // make next of last node of first half to null
        slow->next=nullptr;
        // reverse the second half of the list
        ListNode* curr=second;
        ListNode* prev=nullptr;
        second=second->next;
        while(second){
            curr->next=prev;
            prev=curr;
            curr=second;
            second=second->next;
        }
        curr->next=prev;
        second=curr;
        ListNode* first=head;
        // merge both halves 
        while(first && second){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            first=temp1;
            second->next=temp1;
            second=temp2;
        }


    }
};
