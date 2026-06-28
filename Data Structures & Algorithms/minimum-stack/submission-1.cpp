class MinStack {
    vector<int> res;
    vector<int> min;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(min.empty()||val<=min.back()){min.push_back(val);}
        res.push_back(val);
    }
    
    void pop() {
        if(res.back()==min.back())min.pop_back();
        res.pop_back();
    }
    
    int top() {
        return res.back();
    }
    
    int getMin() {
        return min.back();
    }
};
