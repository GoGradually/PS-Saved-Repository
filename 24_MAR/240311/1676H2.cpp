#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;
template <class T>
class segment_tree {
   private:
    vector<T> tree;

   public:
    segment_tree(int n) { tree.resize(4 * n); }
    T cal(T val1, T val2) { return val1 + val2; }  // make cal function
    void update(int node, int left, int right, int x, T y) {
        if (x < left || x > right) return;
        if (left == right) {
            tree[node] += y;  // decide to method of updating
            return;
        }
        int mid = (left + right) / 2;
        update(node * 2, left, mid, x, y);
        update(node * 2 + 1, mid + 1, right, x, y);
        tree[node] = cal(tree[2 * node], tree[2 * node + 1]);
    }
    T query(int node, int left, int right, int x, int y) {
        if (x > right || y < left) return 0;  // designate NULL
        if (x <= left && right <= y) return tree[node];
        int mid = (left + right) / 2;
        return cal(query(2 * node, left, mid, x, y),
                   query(2 * node + 1, mid + 1, right, x, y));
    }
};
void Solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    segment_tree<int> seg(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += seg.query(1, 0, n - 1, arr[i] - 1, n - 1);
        seg.update(1, 0, n - 1, arr[i] - 1, 1);
    }
    cout << ans << '\n';
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
1. int 오버플로우, out of bounds
2. 특수한 경우(n=1?)
3. 잘못된 가정 & 증명

*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"(문제 특징의 "증명"으로 아이디어)
// {BruteForce, greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화 & 최적화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

*/

// commit 시 피드백할 것 Message로 남겨두기!!