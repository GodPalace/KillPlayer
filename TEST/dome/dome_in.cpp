#include <iostream>
#include <cstdio>
using namespace std;

struct xy {
    int data;
    xy *next;

    explicit xy(int data) {
        this -> data = data;
        next = nullptr;
    }

    ~xy() {
        data = 0;
        next = nullptr;
    }
};

xy *first = new xy(1);

xy* FindNumber(int number) {
    xy *t = first;
    if (first -> data == number) {
        return first;
    }

    while ((t = t -> next) != nullptr) {
        if (t -> data == number) {
            return t;
        }
    }

    return nullptr;
}

int q;
int dome_in() {
    freopen("D:/CLionProjects/TEST/dome/in.in", "r", stdin);
    freopen("D:/CLionProjects/TEST/dome/out.out", "w", stdout);
    cin >> q;

    while (q--) {
        int x, y, o;
        cin >> o;

        if (o == 1) {
            cin >> x >> y;

            xy *temp = FindNumber(x);
            xy *temp2 = temp->next;
            xy *temp3 = new xy(y);

            temp->next = temp3;
            temp3->next = temp2;
        } else if (o == 2) {
            cin >> x;

            xy *temp = FindNumber(x);
            if (temp -> next == nullptr) {
                cout << 0 << endl;
            } else {
                cout << temp -> next -> data << endl;
            }
        } else if (o == 3) {
            cin >> x;

            xy *temp = FindNumber(x);
            xy *temp2 = temp -> next;
            xy *temp3 = temp2 -> next;

            temp -> next = temp3;
            delete temp2;
        }
    }
}
