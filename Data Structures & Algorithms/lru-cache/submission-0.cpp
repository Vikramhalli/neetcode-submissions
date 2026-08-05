class Node{
public:
    int key,val;
    Node*prev,*next;
    Node(int k,int v){
        key=k;
        val=v;
        prev=next=NULL;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int,Node*> mp;
    Node*head,*tail;

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void delnode(Node* node){
        Node* prevnode=node->prev;
        Node* nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
    }

    void insertnode(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node=mp[key];
        delnode(node);
        insertnode(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            delnode(node);
            mp.erase(key);
        }
        if(mp.size()==cap){
            Node* lru=tail->prev;
            delnode(lru);
            mp.erase(lru->key);
        }
        Node* node=new Node(key,value);
        insertnode(node);
        mp[key]=node;
    }
};
