#include <string>
#include <cstdio>
using namespace std;

template <typename T>
class STACK {
    private:
        T *arr;
        int top;
        int size;

    public:
        STACK(int size) {
            if (size <= 0) throw EOF;

            this -> size = size;
            arr = new T[size];
            top = -1;
        }

        STACK() {
            size = 10;
            arr = new T[size];
            top = -1;
        }

        ~STACK() {
            delete[] arr;
        }

        void push(T data) {
            if (top >= size * (4.0F/5.0F)) {
                T *temp = arr;

                size *= 2;
                arr = new T[size];
                memcpy(arr, temp, (size * sizeof(T)) / 2);

                delete[] temp;
            }

            top++;
            arr[top] = data;
        }

        void pop() {
            if (top == -1) return;

            top--;
        }

        T GetTop() {
            if (top == -1) throw EOF;

            return arr[top];
        }

        bool empty() {
            return top == -1;
        }
};
