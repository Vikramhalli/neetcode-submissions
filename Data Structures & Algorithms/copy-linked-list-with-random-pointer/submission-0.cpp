/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=NULL){
            Node* newnode=new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
        }

        temp=head;
        while(temp!=NULL){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            else{
                temp->next->random=NULL;
            }
            temp=temp->next->next;
        }

        temp=head;
        Node* dummy=new Node(-1);
        Node* res=dummy;
        while(temp!=NULL){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};
