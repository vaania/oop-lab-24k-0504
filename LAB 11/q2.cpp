#include <iostream>
#include <exception>
using namespace std;

// Exception classes
class QueueOverflowException : public exception {
};

class QueueUnderflowException : public exception {
};

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int front;
    int rear;
    int size;

public:
    Queue(int cap) : capacity(cap), front(0), rear(0), size(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(T value) {
        if (size == capacity)
            throw QueueOverflowException();

        data[rear] = value;
        rear = (rear + 1) % capacity;
        ++size;
    }

    T dequeue() {
        if (size == 0)
            throw QueueUnderflowException();

        T val = data[front];
        front = (front + 1) % capacity;
        --size;
        return val;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void print() const {
        for (int i = 0; i < size; ++i)
            cout << data[(front + i) % capacity] << " ";
        cout << endl;
    }
};

int main() {
    Queue<int> q(3);

    try {
        cout << "Attempting to enqueue to a full queue..." << endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
    } catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try {
        Queue<int> emptyQueue(2);
        cout << "Attempting to dequeue from an empty queue..." << endl;
        emptyQueue.dequeue();
    } catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
