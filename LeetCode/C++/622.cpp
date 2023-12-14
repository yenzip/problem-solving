class MyCircularQueue {

private:
    vector<int> q;
    int front;
    int size;

public:
    MyCircularQueue(int k) {
        q.resize(k, 0);
        front = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        } 

        q[(front + size) % q.size()] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }

        front = (front + 1) % q.size();
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[(front + size - 1) % q.size()];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return q.size() == size;
    }
};
