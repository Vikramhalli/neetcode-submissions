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

    ListNode* reversell(ListNode* head){
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prevlast;
            prevlast=temp;
            temp=front;
        }
        return prevlast;
    }

    ListNode* getkthnode(ListNode* temp,int k){
        k--;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        while(temp!=NULL){
            ListNode* kthnode=getkthnode(temp,k);
            if(kthnode==NULL){
                if(prevlast){
                    prevlast->next=temp;
                }
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=NULL;
            reversell(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevlast->next=kthnode;
            }
            prevlast=temp;
            temp=nextnode;
        } 
        return head;   
    }
};
