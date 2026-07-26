class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
            return;
        }
        
        int min_val = min(val, st.top().second);
        st.push({val, min_val});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
