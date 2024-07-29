#include <iostream>

template <typename T>
class QUEUE {
    private:
        T *arr;
        int head;
        int tail;
        int size;

    public:
        QUEUE() {
            size = 10;
            head = -1;
            tail = -1;
            arr = new T[size];
        }

        QUEUE(int size) {
            if (size <= 0) throw EOF;

            this -> size = size;
            head = -1;
            tail = -1;
            arr = new T[size];
        }

        ~QUEUE() {
            delete[] arr;
        }

        void push(T data) {
            if (head == -1) head = 0;

            if (tail >= size * (4.0F/5.0F)) {
                T *temp = arr;

                size *= 2;
                arr = new T[size];
                memcpy(arr, temp + (head * sizeof(T)), ((size - head) * sizeof(T)) / 2);
                tail -= head;
                head = 0;

                delete[] temp;
            }

            tail++;
            arr[tail] = data;
        }

        void pop() {
            if (head > tail || head == -1) throw EOF;

            head++;
        }

        T GetTop() {
            return arr[head];
        }
};
