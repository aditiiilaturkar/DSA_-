class LRUCache {
public:
    list<int>ll;
    // map<key, pair<node address, value>>mp
    map<int, pair<list<int>::iterator, int>>mp;

    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    void remove(int k){
        ll.erase(mp[k].first);
        mp.erase(k);
    }

    void addToFront(int key, int val){
        ll.push_front(key);
        pair<list<int>::iterator, int>temp = {ll.begin(), val};
        mp[key] = temp;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }else{
            int ans = mp[key].second;
            remove(key);
            addToFront(key, ans);
            return ans;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(mp.size()==cap){
                remove(ll.back());
            }
            addToFront(key, value);
        }else{
            remove(key);
            addToFront(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */