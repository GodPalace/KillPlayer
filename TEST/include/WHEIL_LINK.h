#include <cwchar>

template <typename T>

struct NODE {
    T data;
    NODE *next;
    NODE *prev;

    NODE(T data) {
        this -> data = data;

        next = this;
        prev = this;
    }

    void add(NODE *node) {
        NODE *temp = this ->prev;

        node ->next = this;
        this ->prev = node;

        node ->prev = temp;
        temp ->next = node;
    }

    T GetData() {
        return data;
    }

    NODE* GetNext() {
        return next;
    }

    NODE* GetPrev() {
        return prev;
    }
};
