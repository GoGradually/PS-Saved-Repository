#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

vector<int> arr;

template <class T>
class segment_tree {
   private:
    vector<T> tree;

   public:
    segment_tree(int n) { tree.resize(4 * n); }
    T cal(T val1, T val2) { return max(val1, val2); }
    void update(int node, int left, int right, int x, T y) {
        if (left > x || right < x) return;
        if (left == right) {
            tree[node] = y;
            return;
        }
        int mid = (left + right) / 2;
        update(node * 2, left, mid, x, y);
        update(node * 2 + 1, mid + 1, right, x, y);
        tree[node] = cal(tree[node * 2], tree[node * 2 + 1]);
    }
    T query(int node, int left, int right, int x, int y) {
        if (x > right || y < left) return 0;
        if (x <= left && right <= y) return tree[node];
        int mid = (left + right) / 2;
        int lVal = query(node * 2, left, mid, x, y);
        int rVal = query(node * 2 + 1, mid + 1, right, x, y);
        return cal(lVal, rVal);
    }
};

void Solve() {
    int n;
    cin >> n;
    arr.resize(n);
    segment_tree<int> seg_tree(n);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        seg_tree.update(1, 0, n - 1, i, arr[i]);
    }
    vector<int> dest(n);
    for (int i = 0; i < n; i++) {
        cin >> dest[i];
        pq.push({-dest[i], i});
    }
    while (!pq.empty()) {
        int index, nowDest;
        tie(nowDest, index) = pq.top();
        pq.pop();
        bool ok = false;
        nowDest *= -1;
        int left = 0, right = index;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (seg_tree.query(1, 0, n - 1, mid, index) >= dest[index]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right >= 0 &&
            seg_tree.query(1, 0, n - 1, right, index) == dest[index]) {
            ok = true;
        }
        left = index, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (seg_tree.query(1, 0, n - 1, index, mid) >= dest[index]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left < n &&
            seg_tree.query(1, 0, n - 1, index, left) == dest[index]) {
            ok = true;
        }
        if (!ok) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
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
// 1. "추론"(문제 특징의 "증명"으로 아이디어){greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.

dest 의 V자 형태
dest가 자기보다 작은쪽으로는 못감
*/

// commit 시 피드백할 것 Message로 남겨두기!!