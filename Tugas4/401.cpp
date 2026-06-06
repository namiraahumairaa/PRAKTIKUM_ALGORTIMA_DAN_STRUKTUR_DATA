#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

void insert(Node** root, int val) {
    if (*root == NULL) {
        Node* baru = new Node;
        baru->data = val;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *root = baru;
    } else if (val < (*root)->data) {
        insert(&((*root)->kiri), val);
    } else if (val > (*root)->data) {
        insert(&((*root)->kanan), val);
    }
}

int hitungTinggiDanDiameter(Node* root, int& max_diameter) {
    if (root == NULL) {
        return 0;
    }
    
    int tinggiKiri = hitungTinggiDanDiameter(root->kiri, max_diameter);
    int tinggiKanan = hitungTinggiDanDiameter(root->kanan, max_diameter);
    
    max_diameter = max(max_diameter, tinggiKiri + tinggiKanan);
    
    return max(tinggiKiri, tinggiKanan) + 1;
}

int getDiameter(Node* root) {
    int max_diameter = 0;
    hitungTinggiDanDiameter(root, max_diameter);
    return max_diameter;
}

int main() {
    int n;
    cin >> n;
    
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(&root, val);
    }
    
    cout << getDiameter(root) << endl;
    
    return 0;
}