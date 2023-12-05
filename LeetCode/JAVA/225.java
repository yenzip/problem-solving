class MyStack {
    private Queue<Integer> q, tmpQ;
    private int stkTop;

    public MyStack() {
        q = new LinkedList<>();
        tmpQ = new LinkedList<>();
        stkTop = 0;
    }
    
    public void push(int x) {
        q.add(x);
        stkTop = x;
    }
    
    public int pop() {
        while(q.size() > 1) {
            stkTop = q.peek();
            tmpQ.add(q.poll());
        }

        int stkPop = q.poll();

        Queue<Integer> swapQ = q;
        q = tmpQ;
        tmpQ = swapQ;

        return stkPop;
    }
    
    public int top() {
        return stkTop;
    }
    
    public boolean empty() {
        return q.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */