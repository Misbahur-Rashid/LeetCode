// class MyCircularQueue {
// public:
//     vector<int> q;
//     int head, curSize;
    
//     /** Initialize your data structure here. Set the size of the queue to be k. */
//     MyCircularQueue(int k) {
//         q = vector<int>(k, -1);
//         head = 0; //head is inclusive
//         curSize = 0;
//     }
    
//     /** Insert an element into the circular queue. Return true if the operation is successful. */
//     bool enQueue(int value) {
//         if(isFull()) return false;
//         //head+curSize: the space after rear
//         q[(head+curSize)%q.size()] = value;
//         curSize++;
//         return true;
//     }
    
//     /** Delete an element from the circular queue. Return true if the operation is successful. */
//     bool deQueue() {
//         if(isEmpty()) return false;
//         q[head++] = -1;
//         curSize--;
//         return true;
//     }
    
//     /** Get the front item from the queue. */
//     int Front() {
//         return q[head];
//     }
    
//     /** Get the last item from the queue. */
//     int Rear() {
//         return q[(head+curSize-1)%q.size()];
//     }
    
//     /** Checks whether the circular queue is empty or not. */
//     bool isEmpty() {
//         return curSize == 0;
//     }
    
//     /** Checks whether the circular queue is full or not. */
//     bool isFull() {
//         return curSize == q.size();
//     }
// };

 class MyCircularQueue {

private:
    int front, tail;
    vector<int> data;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {

        front = tail = 0;
        data.clear();
        for(int i = 0; i <= k; i ++)
            data.push_back(-1);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        data[tail] = value;
        tail = (tail + 1) % data.size();
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        front = (front + 1) % data.size();
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
        return data[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
            return -1;
        int index = tail - 1;
        if(index < 0)
            index += data.size();
        return data[index];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == tail;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail + 1) % data.size() == front;
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */