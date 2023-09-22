#include <bits/stdc++.h>
using namespace std;

vector<int> arr;  // authorize data type of arr
// arr = [0 : n-1]
// root of tree = 1
template <class T>
class segment_tree {
   private:
    vector<T> tree;

   public:
    segment_tree(int n) { tree.resize(4 * n); }
    T cal(T val1, T val2) { return; }  // make cal function
    void update(int node, int left, int right, int x, T y) {
        if (x < left || x > right) return;
        if (left == right) {
            tree[node] = y;  // decide to method of updating
            return;
        }
        int mid = (left + right) / 2;
        update(node * 2, left, mid, x, y);
        update(node * 2 + 1, mid + 1, right, x, y);
        tree[node] = cal(tree[2 * node], tree[2 * node + 1]);
    }
    T query(int node, int left, int right, int x, int y) {
        if (x > right || y < left) return null;  // designate NULL
        if (x <= left && right <= y) return tree[node];
        int mid = (left + right) / 2;
        return cal(query(2 * node, left, mid, x, y),
                   query(2 * node + 1, mid + 1, right, x, y));
    }
};