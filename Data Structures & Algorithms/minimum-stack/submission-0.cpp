class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minst.push(val);
        }
        else{
            if(val<=minst.top()){
                minst.push(val);
            }
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top()==minst.top()){
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
