class MyCircularQueue {
private: int front=0,rear=0;
private: int *queue;
private: int k;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        this->k = k+1;//要多开一个空间
        queue = new int[k+1];
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(!isFull()) {
            queue[rear] = value;
            rear=(rear+1)%k;
            return true;
        } else {
            return false;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(!isEmpty()){
            front = (front+1)%k;
            return true;
        } else {
            return false;
        }
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return queue[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return queue[(rear-1+k)%k];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == rear;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (rear+1)%k == front;
    }
};