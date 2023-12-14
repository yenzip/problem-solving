class MyCircularQueue {

    private int[] q;
    private int front;
    private int size;
    private int capacity;

    public MyCircularQueue(int k) {
        q = new int[k];
        front = size = 0;
        capacity = k;
    }
    
    public boolean enQueue(int value) {
        if(isFull()) {
            return false;
        }

        q[(front + size) % capacity] = value;
        size++;
        return true;
    }
    
    public boolean deQueue() {
        if(isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    public int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    public int Rear() {
        return isEmpty() ? -1 : q[(front + size - 1) % capacity];
    }
    
    public boolean isEmpty() {
        return size == 0;
    }
    
    public boolean isFull() {
        return size == capacity;
    }
}