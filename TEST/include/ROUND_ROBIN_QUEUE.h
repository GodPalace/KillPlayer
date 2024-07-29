#include <iostream>

template <typename T>
class ROUND_ROBIN_QUEUE {
private:
    T *arr;
    int head;
    int tail;
    int size;

public:
    ROUND_ROBIN_QUEUE() {
        size = 10;
        head = -1;
        tail = -1;
        arr = new T[size];
    }

    ROUND_ROBIN_QUEUE(int size) {
        if (size <= 0) {
            cerr << "line : " << __LINE__ << endl;
            throw EOF;
        };

        this -> size = size;
        head = -1;
        tail = -1;
        arr = new T[size];
    }

    ~ROUND_ROBIN_QUEUE() {
        delete[] arr;
    }

    void push(T data) {
        if (head == -1) head = 0;

        if (tail == size - 1) {
            if (head > 0) {
                tail = 0;
                arr[tail] = data;
            } else {
                cerr << "line : " << __LINE__ << endl;
                throw EOF;
            }
        }

        //if (tail == head - 1) {
        //    cerr << "line : " << __LINE__ << endl;
        //    throw EOF;
        //}

        tail++;
        arr[tail] = data;
    }

    void pop() {
        if (head == -1) {
            cerr << "line : " << __LINE__ << endl;
            throw EOF;
        }

        head++;
    }

    T GetTop() {
        return arr[head];
    }
};
