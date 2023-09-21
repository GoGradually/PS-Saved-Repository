#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

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
    T cal(T val1, T val2) { return max(val1, val2); }  // make cal function
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
        if (x > right || y < left) return 0;  // designate NULL
        if (x <= left && right <= y) return tree[node];
        int mid = (left + right) / 2;
        T lVal = query(2 * node + 1, left, mid, x, y);
        T rVal = query(2 * node + 2, mid + 1, right, x, y);
        return cal(lVal, rVal);
    }
    void update(int x, T y) { update(0, 1, N, x, y); }
    T query(int x, int y) { return query(0, 1, N, x, y); }
};
void Solve() {
    int n, m;
    cin >> n >> m;
    arr.resize(m + 1);
    int mx = 0;
    for (int i = 1; i <= m; i++) {
        cin >> arr[i];
    }
    segment_tree<int> seg_tree(m+1);
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        if (y1 > y2) { swap(y1, y2); swap(x1, x2); }
        int mx = seg_tree.query(y1, y2);
        if (x1 % k == x2 % k && y1 % k == y2 % k) {
            if (mx < mx / k * (k) + x1 % k && mx / k * (k) + x1 % k <= n) {
                cout << "YES\n";
            } else if (mx < mx / k * (k) + x1 % k + k  && mx / k * (k) + x1 % k + k <= n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }

        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}

/*
찾아야 할 것들
*int 오버플로우, out of bounds
*특수한 경우(n=1?)
*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"(문제 특징의 증명으로 아이디어){greedy, D&C, DP, graph})
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"

/*
take notes.

*/