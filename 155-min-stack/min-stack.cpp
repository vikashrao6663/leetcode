class MinStack {
public:
    stack<pair<int,int>> st; // {value, currentMin}

    MinStack() {}

    void push(int val) {

        if(st.empty()) {
            st.push({val, val});
        }
        else {
            int curMin = min(val, st.top().second);
            st.push({val, curMin});
        }
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