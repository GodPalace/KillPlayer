#include <cstdio>

template <typename T>
struct LINK{
    private:
        struct NODE {
            T data;
            NODE *prev;
            NODE *next;

            NODE(T data) {
                this -> data = data;
            }

            ~NODE() {
                delete data;
            }
        };

        int size;
        NODE *last;
        NODE *first;
        NODE *current;

    public:
        LINK() {
            size = 0;
            current = NULL;
        }

        void add(T data) {
            NODE *node = new NODE(data);
            if (current == NULL) current = node;

            if (size == 0) {
                first = node;
                node -> prev = NULL;
                node -> next = NULL;
            } else {
                node -> prev = last;
                node -> next = NULL;
                last -> next = &node;
            }

            last = node;
            size++;
        }

        void remove() {
            NODE *node = last -> prev;
            node -> prev = NULL;
            last = node;
            size--;

            delete node;
        }

        T GetNext() {
            if (current -> next == NULL) return NULL;

            NODE *node = current -> next;
            current = node;

            return node -> data;
        }

        T GetPrev() {
            if (current -> prev == NULL) return NULL;

            NODE *node = current -> prev;
            current = node;

            return node -> data;
        }
};
