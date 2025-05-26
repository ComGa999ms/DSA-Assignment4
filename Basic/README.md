# DSA Basic-Assignment4

Họ và tên: Nguyễn Đăng Khoa

Lớp: ATTN2024

MSSV: 24520825

## Tree: Hieght of Tree	
```C++
int height(Node* root) {
    if (root == NULL) return 0;

    // tính chiều cao từ cây con trái, phải
    int L = height(root->left);
    int R = height(root->right);

    // Lấy cây con có chiều cao cao hơn + 1 
    return (L > R ? L : R) + 1;
}
```

## Binary Search Tree: Insert (không dùng đệ quy)
```C++
Node * insert(Node * root, int data) {
    Node *newNode = new Node(data);

    // Nếu nó là node lá thì add vào 
    if (root == NULL) return newNode;

    Node *cur = root;
    Node *par = NULL;

    // Tìm vị trí add
    while (cur != NULL) {
        par = cur;

        // Nếu data < current->data thì nhảy về trái 
        if (data < cur->data) cur = cur->left;
        else cur = cur->right; // Ngược lại thì nhảy phải
    }        

    // Nếu data < parret->left thì add left
    if (data < par->data) par->left = newNode;
    else par->right = newNode; // add right
        
    return root;
}
```
## Binary Search Tree: Insert	
Ý tưởng tương tự nhưng ở đây gọi đệ qui. 
```C++
Node * insert(Node * root, int data) {
    if (root == NULL) return new Node(data);

    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
        
    return root;
}
```
## Tree: levelOrder Traversal - Duyệt cây BST theo chiều rộng	

Bài này bfs trên cây BST. 
```C++
void levelOrder(Node *root) {
    if (root == NULL) return ;

    Node *q[505];
    int i = 0, front = 0;
    q[i++] = root; // đẩy node gốc vào

    while (front < i) {
        // Lấy node đỉnh ra
        Node *cur = q[front++];

        cout << cur->data << ' ';

        // Nếu trái, phải có node con thì bfs  
        if (cur->left != NULL) q[i++] = cur->left;
        if (cur->right != NULL) q[i++] = cur->right;
    }
}
```
## Tree: Inorder Traversal (LNR) II - Duyệt cây BST theo LNR không đệ quy	
Bài này không được dệ quy nên chúng ta code stack bằng mảng.
```C++
void inOrder(Node *root) {
    if (root == NULL) return;

    Node *st[505];
    int top = -1;

    Node *cur = root;
    while (cur != NULL || top >= 0) {
        // duyệt hết gốc con trái 
        while (cur != NULL) {
            st[++top] = cur;
            cur = cur->left;
        }

        // Xong tới node 
        cur = st[top--];
        cout << cur->data << ' ';

        // Cuối cùng là left
        cur = cur->right;
    }
}
```
## Tree: Inorder Traversal (LNR) - Duyệt cây BST theo LNR	
Ý tưởng duyệt giống bài trên nhưng ở đây được dùng đệ quy.
```C++
void inOrder(Node *root) {
    if (root == NULL) return;

    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}
```
## Tree: Postorder Traversal (LRN) II - Duyệt cây BST theo LRN không đệ quy
Bài này không đệ quy nên code stack bằng mảng.	
```C++
void inOrder(Node *root) {
    if (root == NULL) return ;

    Node *st[505];
    int top = -1;

    Node *cur = root;
    Node *LastVis = NULL;

    // Duyệt hết gốc con trái 
    while (cur != NULL || top >= 0) {
        while (cur != NULL) {
            st[++top] = cur;
            cur = cur->left;
        }

        cur = st[top];

        // Phải
        if (cur->right != NULL && cur->right != LastVis) cur = cur->right;
        else {
            // Node
            cout << cur->data << ' ';
            LastVis = cur;
            top--;
            cur = NULL;
        }
    }
}
```
## Tree: Postorder Traversal (LRN) - Duyệt cây BST theo LRN	
Cách duyệt tương tự bài trên nhưng bài này code theo kiểu đệ quy.
```C++
void postOrder(Node *root) {
    if (root == NULL) return;
        
    postOrder(root->left);
    postOrder(root->right);

    cout << root->data << ' ';
}    
```
## Binary Search Tree: Nút chung gần nhất	
```C++
Node *lca(Node *root, int v1, int v2) {
    if (root == NULL) return NULL;

    // Nếu node hiện tại cùng bé hơn 2 node còn lại thì nhảy trái, tương tự thì nhảy phải.
    if (v1 < root->data && v2 < root->data) return lca(root->left, v1, v2);
    if (v1 > root->data && v2 > root->data) return lca(root->right, v1, v2);

    return root;
}
```