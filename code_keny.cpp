#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Cấu trúc 1 Nút (Node) trên Cây AVL
struct Node {
    int info;    // Thông tin (key)
    int height;  // Chiều cao của Node
    Node *left, *right;  // Con trỏ đến 2 nhánh con trái và phải
};

// Khai báo Cây Gốc
Node *root;

// Hàm khởi tạo
void Init() {
    root = NULL;
}

// Kiểm tra cây rỗng
int Empty() {
    return (root == NULL);
}

// Hàm tính chiều cao của một nút
int height(Node *n) {
    if (n == NULL) return 0;
    return 1 + std::max(height(n->left), height(n->right));
}

// Hàm tính độ cân bằng của một nút
int getBalance(Node *n) {
    return height(n->left) - height(n->right);
}

// Hàm tạo một Nút mới
Node *NewNodeAVL(int x) {
    Node *p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    p->height = 1; // Chiều cao của Nút mới là 1
    return p;
}

// Hàm quay phải (Right Rotate)
Node *rightRotate(Node *n) {
    Node *t = n->left;
    Node *r = t->right;
    t->right = n;
    n->left = r;
    return t;
}

// Hàm quay trái (Left Rotate)
Node *leftRotate(Node *n) {
    Node *t = n->right;
    Node *r = t->left;
    t->left = n;
    n->right = r;
    return t;
}

// Hàm tìm Nút có giá trị nhỏ nhất trong cây
Node *minValue(Node *n) {
    if (n->left == NULL) {
        return n;
    }
    return minValue(n->left);
}

// Hàm thêm Nút mới vào Cây AVL
Node *InsertAVL(Node *root, int x) {
    if (root == NULL) return NewNodeAVL(x);
    else if (x < root->info) {
        root->left = InsertAVL(root->left, x);
    } else {
        root->right = InsertAVL(root->right, x);
    }

    // Cập nhật chiều cao của Nút
    root->height = 1 + std::max(height(root->left), height(root->right));

    // Cân bằng cây AVL nếu cần
    int b = getBalance(root);
    if (b > 1) {
        if (getBalance(root->left) < 0) {
            root->left = leftRotate(root->left); // Quay trái đối với nhánh trái
        }
        return rightRotate(root);
    } else if (b < -1) {
        if (getBalance(root->right) > 0) {
            root->right = rightRotate(root->right); // Quay phải đối với nhánh phải
        }
        return leftRotate(root);
    }

    return root;
}

// Hàm xóa Nút khỏi Cây AVL
Node *DeleteAVLNode(Node *root, int x) {
    if (root == NULL) return root;
    else if (x < root->info) {
        root->left = DeleteAVLNode(root->left, x);
    } else if (x > root->info) {
        root->right = DeleteAVLNode(root->right, x);
    } else {
        if (!root->right || !root->left) {
            Node *t = !root->right ? root->left : root->right;
            delete root;
            return t;
        }
        Node *t = minValue(root->right);
        root->info = t->info;
        root->right = DeleteAVLNode(root->right, t->info);
    }

    root->height = 1 + std::max(height(root->left), height(root->right));

    return root;
}
//         4 (Height: 3)
//        / \
//     2 (Height: 2)  6 (Height: 2)
//    / \   / \
//  1(Height: 1) 3(Height: 1) 5(Height: 1) 7(Height: 1)


// Hàm duyệt Cây theo thứ tự cấp độ (Level Order) và in ra chiều cao của từng nút
void levelOrder(Node *root) {
    if (root == NULL) return;

    std::queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        q.pop();
        std::cout << "Node: " << root->info << ", Height: " << root->height << std::endl;

        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
    }
}

int main() {
    Node *root = NULL;
    for (int i = 1; i <= 7; i++) {
        root = InsertAVL(root, i); // Nạp từ 1 -> 7 vào cây AVL
    }

    std::cout << "LevelOrder Traversal with Heights: \n";
    levelOrder(root);

    root = DeleteAVLNode(root, 1); // Xóa nút có giá trị 1
    std::cout << "\nAfter Deleting Node 1: \n";
    levelOrder(root);

    root = DeleteAVLNode(root, 4); // Xóa nút có giá trị 4
    std::cout << "\nAfter Deleting Node 4: \n";
    levelOrder(root);

    return 0;
}
