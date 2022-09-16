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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode *temp=head;
        int count=1;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        if(k>count){
            k=k%count;
        }
        k=count-k;
        if(k==0 || k==count) return head;
        int i=0;
        ListNode* curr=head;
        while(i<k-1 && head){
            curr=curr->next;
            i++;
        }
        temp->next=head;
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};