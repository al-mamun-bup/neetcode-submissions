struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key_, int val_){
        key = key_;
        val = val_;
    }
};
class LRUCache {
public:
    // step 1 : build the struct doubly linked list
    // step 2 : define a hash map of node with head and tail
    int capacity;
    unordered_map<int,Node*>dic;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        // step 3 : every time while fixing the capacity build the doubly linked
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // edge case check first if not present in the dictionary return -1
        if(dic.find(key) == dic.end()){
            return -1;
        }
        // now made the cache by removing that node and add at the top LRU
        Node* node = dic[key];
        remove(node);
        add(node);

        return node->val;


    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev; 
    }

    void add(Node* node){
        // add at the last and again fix the tail which is -1.
        Node* previousEnd = tail->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = tail;

        tail->prev = node;

    }
    
    void put(int key, int value) {
        if(dic.find(key) != dic.end()){
            Node* oldNode = dic[key];

            remove(oldNode);
        }

        Node* node = new Node(key,value);
        dic[key] = node;

        add(node);
        if(dic.size() > capacity){
            Node* delNode = head->next;
            remove(delNode);
            dic.erase(delNode->key);
        }
    }
};
