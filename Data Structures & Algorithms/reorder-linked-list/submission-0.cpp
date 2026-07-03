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
        vector<ListNode*> temp;
        ListNode* curr=head;
        ListNode* root=head;
        while(curr){
            temp.push_back(curr);
            curr=curr->next;
        }
        int i=1,j=temp.size()-1;
        while(i<=j){
            if(i==j) {
                root->next=temp[i++];
                j--;
                root=root->next;
                root->next=nullptr;
                break;
            }
            root->next=temp[j--];
            root=root->next;
            root->next=temp[i++];
            root=root->next;
        }
        root->next=nullptr;


    }
};
