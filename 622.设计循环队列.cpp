#include <vector>

using std::vector;

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
class MyCircularQueue {
public:
    // use 1 extra space
    MyCircularQueue(int k) {
        scale = k + 1;
        vec.resize(scale, 0);
        front = 0;
        rear = 0;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        vec[rear] = value;
        rear = (rear + 1) % scale;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % scale;
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return vec[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return vec[(rear - 1 + scale) % scale];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % scale == front;
    }

private:
    vector<int> vec;
    int front;
    int rear;
    int scale;
};
