# DSA Advance-Assignment4

Họ và tên: Nguyễn Đăng Khoa

Lớp: ATTN2024

MSSV: 24520825

## khangtd.KetBan

Bài này dùng 2 mảng ```L[i], R[i]``` lưu vị trí bên trái và bên phải của $i$.
```C++
/// xóa vị các ràng buộc tại u
int lx = L[u], rx = R[u];
R[lx] = rx;
L[rx] = lx;

// Chuyển u sang trái v
int ri = R[v]; 
L[u] = v;
R[u] = ri;
R[v] = u;
L[ri] = u;
```


## khangtd.HuffmanCoding	

Đầu tiên build cây theo đề bài yêu cầu 
```C++
for (int T : s) cnt[T]++; // đếm tần số 
for (int i = 0; i <= 255; ++i) if (cnt[i]) {
    ++n;
    Set.insert(pii(cnt[i], n)); // Tạo node lá
    a[n] = cnt[i];
}

if (sz(Set) == 1) { // TH có đúng 1 node 
    ++n;
    Set.insert(pii(0, n));
    a[n] = 0;
}

while (sz(Set) > 1) {
    pii t1 = *Set.begin(); Set.erase(Set.begin());
    pii t2 = *Set.begin(); Set.erase(Set.begin());

    ++n;

    // Cộng 2 node lá 
    int newValue = t1.fi + t2.fi; 
    adj[n].push_back(t1.se);
    adj[n].push_back(t1.se);

    // Tạo node mới 
    Set.insert(pii(newValue, n));
}
```
Và sau khi tạo được cây theo đề bài thì cuối cùng chỉ cần dfs để tính đáp án đề bài 
```C++
void dfs(int u, int high) {
    bool check = 0; // check đỉnh u có phải là lá hay khôngkhông

    for (int v : adj[u]) {
        check = 1;
        dfs(v, high + 1);
    }

    if (!check) res += a[u] * high;
}

dfs(n, 0);
cout << res;
```
## khangtd.HoaNhac
Bài này lấy một ```stack <pair<int, int>>``` với first lưu độ cao người $i$, second lưu số người thấp hơn $h_i$ đứng trước đó.
```C++
int res = 0;
stack <pii> st;

for (int i = 1; i <= n; ++i) {
    int cnt = 1;
    
    while (sz(st) && st.top().fi <= h[i]) { 
        res += st.top().se;

        // TH top = h[i] nên h[i] có thêm đúng cnt cặp thỏa 
        if (h[i] == st.top().fi) cnt += st.top().se; 
        st.pop();
    }
    
    if (sz(st)) ++res;
    st.push(pii(h[i], cnt));
}
cout << res;
```
## Tree: levelOrder Traversal - Duyệt cây BST theo chiều rộng	
```C++
void levelOrder(Node *root) {
    if (root == NULL) return ;

    queue <Node*> q;
    q.push(root);

    while (q.size()) {
        Node* u = q.front(); q.pop();
        cout << u->data << ' ';

        // Nếu trái, phải có node con thì bfs 
        if (u->left != NULL) q.push(u->left);
        if (u->right != NULL) q.push(u->right);
    }
}
```