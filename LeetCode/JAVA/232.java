class MyQueue {
    Stack<Integer> stk, tmpStk;

    public MyQueue() {
        stk = new Stack<>();
        tmpStk = new Stack<>();
    }
    
    public void push(int x) {
        stk.push(x);
    }
    
    public int pop() {
        while(stk.size() > 1) {
            tmpStk.push(stk.peek());
            stk.pop();
        }

        int popQ = stk.peek();
        stk.pop();

        while(!tmpStk.isEmpty()) {
            stk.push(tmpStk.peek());
            tmpStk.pop();
        }

        return popQ;
    }
    
    public int peek() {
        while(stk.size() > 1) {
            tmpStk.push(stk.peek());
            stk.pop();
        }

        int front = stk.peek();

        while(!tmpStk.isEmpty()) {
            stk.push(tmpStk.peek());
            tmpStk.pop();
        }

        return front;  
    }
    
    public boolean empty() {
        return stk.isEmpty();
    }
}