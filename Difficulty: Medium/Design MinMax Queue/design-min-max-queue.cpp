class SpecialQueue {
  public:
    map<int,int>mp;
    queue<int>q;
    
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        mp[x]++;
    }

    void dequeue() {
        // Remove element from the queue
        int fr=q.front();q.pop();
        mp[fr]--;
        if(mp[fr] == 0) mp.erase(fr);
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        return mp.begin()->first;
    }

    int getMax() {
        // Get maximum element
        return (--mp.end())->first;
    }
};