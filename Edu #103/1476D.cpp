#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

struct DisjointSet {
    vector<int> parent, rank, size;
    DisjointSet(int n) : parent(n), rank(n, 1), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int now) {
        if (parent[now] == now) return now;
        return parent[now] = find(parent[now]);
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        if (rank[u] == rank[v]) rank[u]++;
    }
    int find_size(int now) { return size[find(now)]; }
};

void Solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    string str;
    cin >> str;
    DisjointSet uf(2 * n + 2);

    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            if (str[i - 1] == 'L') {
                uf.merge(2 * (i - 1) + 1, 2 * i);
            } else {
                uf.merge(2 * (i - 1), 2 * i + 1);
            }
        }
        if (i < n) {
            if (str[i] == 'R') {
                uf.merge(2 * i, 2 * (i + 1) + 1);
            } else {
                uf.merge(2 * i + 1, 2 * (i + 1));
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << uf.find_size(i * 2) << ' ';
    }
    cout << '\n';
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

*/

// commit 시 피드백할 것 Message로 남겨두기!!