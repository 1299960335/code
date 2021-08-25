class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if(st.empty()){
            minum = x;
            st1.push(x);
        }
        if(x <= minum){
            minum = x;
            st1.push(x);
        }
        st.push(x);
    }
    
    void pop() {
        if(st.empty()){
            return ;
        }
        if(st.top() == st1.top()){
            st1.pop();
            minum = st1.top();
        }
        st.pop();
    }
    
    int top() {
       return st.top();
    }
    
    int min() {
        return minum;
    }
private:
    stack<int> st;
    stack<int> st1;
    int minum = 0;
};