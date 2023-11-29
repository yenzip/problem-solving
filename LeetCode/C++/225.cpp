class MyStack {
private:
    queue<int> q, tmpQ;
    int stkTop;
public:
    MyStack() {
        stkTop = 0;
    }
    
    void push(int x) {
        q.push(x);
        stkTop = x;
    }
    
    int pop() {
        while(q.size() > 1) {
            stkTop = q.front();
            tmpQ.push(q.front());
            q.pop();
        }

        int stkPop = q.front();
        q.pop();

        swap(q, tmpQ);

        return stkPop;
    }
    
    int top() {
        return stkTop;
    }
    
    bool empty() {
        return q.empty();
    }
};