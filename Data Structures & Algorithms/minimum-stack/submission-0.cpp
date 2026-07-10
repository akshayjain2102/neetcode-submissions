class MinStack {
        vector<int> arr;
        int t = -1;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        t++;
        arr.push_back(val);
    }
    
    void pop() {
        if(t == -1) return;
        arr.pop_back();
        t--;
    }
    
    int top() {
        return arr[t];
    }
    
    int getMin() {
        int mini = INT_MAX;
        for(int i=0;i<=t;i++){
            mini = min(mini,arr[i]);
        }
        return mini;
    }
};
