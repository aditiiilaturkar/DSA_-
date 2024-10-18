class LRUCache {
public:
    struct node {
        int val;
        int key;
        node* prev;
        node* next;
        node(int k, int v){
            key = k;
            val = v;
        }
    };
    unordered_map<int, node*>mp;
    node* left = new node(0, 0); 
    node* right = new node(0, 0); 

    int cap;

    LRUCache(int capacity) {
        cap = capacity;    
        left->next=right;
        right->prev = left;
    }
    void remove(node* n){
        mp.erase(n->key);
        n->prev->next=n->next;
        n->next->prev=n->prev;
    }
    void addAtFront(int k, int v){
        node* temp = new node(k, v);
        mp[k] = temp;
        temp->next=left->next;
        temp->prev=left;
        left->next->prev=temp;
        left->next=temp;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            if(mp[key] == NULL) return -1;
            int ans = mp[key]->val;
            remove(mp[key]);
            addAtFront(key, ans);
            return ans;
        }else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            remove(mp[key]);
        }
        if(mp.size() == cap){
            remove(right->prev);
        }
        addAtFront(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */