class LRUCache {
public:
    int n;
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator,int>> mpp;

    LRUCache(int capacity) {
        n = capacity;
    }
    void makeRecentlyUsed(int key){
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();
    }
    int get(int key) {
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        makeRecentlyUsed(key);

        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            mpp[key].second = value;
            makeRecentlyUsed(key);
        }else{
            dll.push_front(key);
            mpp[key] = {dll.begin(), value};
            n--;

            if(n < 0){
                int keyToBeDeleted = dll.back();
                mpp.erase(keyToBeDeleted);
                dll.pop_back();
                n++;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */