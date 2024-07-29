#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template<typename T>
class BiTree {
    T data;
    BiTree *left;
    BiTree *right;

public:
    explicit BiTree(T data) {
        this -> data = data;

        left = nullptr;
        right = nullptr;
    }

    void AddLeft(BiTree *parent) {
        if (parent == nullptr) return;

        left = parent;
    }

    void AddRight(BiTree *parent) {
        if (parent == nullptr) return;

        right = parent;
    }

    BiTree* GetLeft() {
        return left;
    }

    BiTree* GetRight() {
        return right;
    }

    T GetData() {
        return data;
    }
};

template <typename T>
void ListPreamble(BiTree<T> *root) {
    cout << root -> GetData() << endl; //中

    if (root -> GetLeft() != nullptr) ListPreamble(root -> GetLeft());   //左
    if (root -> GetRight() != nullptr) ListPreamble(root -> GetRight());   //右
}

int main() {
    BiTree<int> *root = new BiTree<int>(0);

    BiTree<int> *temp, *temp2 = root;
    for (int i = 0; i < 5; i++) {
        temp = new BiTree(i);

        temp2 -> AddLeft(temp);

        temp2 = temp2 -> GetLeft();
    }

    ListPreamble(root);
}
