#include <bits/stdc++.h>
using namespace std;

vector<int> arr;  // authorize data type of arr
// arr[1~n]
// root of tree = 0
template <class T>
class segment_tree {
   private:
    vector<T> tree;
    int N;

   public:
    segment_tree(int n) {
        N = n - 1;
        int h = (int)ceil(log2(n));
        int size = 1 << (h + 1);
        tree.resize(size);
        build(0, 1, N);
    }
    T cal(T val1, T val2) { return; }  // make cal function
    void recalculate(int node) {
        tree[node] = cal(tree[2 * node + 1], tree[2 * node + 2]);
    }
    void build(int node, int left, int right) {
        if (left == right)
            tree[node] = arr[left];
        else {
            int mid = (left + right) / 2;
            build(node * 2 + 1, left, mid);
            build(node * 2 + 2, mid + 1, right);
            recalculate(node);
        }
    }
    void update(int node, int left, int right, int x, T y) {
        if (x < left || x > right) return;
        if (left == right) {
            tree[node] = y;  // decide to method of updating
            return;
        }
        int mid = (left + right) / 2;
        update(node * 2 + 1, left, mid, x, y);
        update(node * 2 + 2, mid + 1, right, x, y);
        recalculate(node);
    }
    T query(int node, int left, int right, int x, int y) {
        if (x > right || y < left) return null;  // designate NULL
        if (x <= left && right <= y) return tree[node];
        int mid = (left + right) / 2;
        T lVal = query(2 * node + 1, left, mid, x, y);
        T rVal = query(2 * node + 2, mid + 1, right, x, y);
        return cal(lVal, rVal);
    }
    void update(int x, T y) { update(0, 1, N, x, y); }
    T query(int x, int y) { return query(0, 1, N, x, y); }
};