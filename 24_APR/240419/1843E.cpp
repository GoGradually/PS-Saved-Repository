#include <bits/stdc++.h>
#define ll long long
#define INF ((int)1e9 + 10)
#define lINF ((ll)1e18 + 10LL)
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> range(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        range[i] = {a, b};
    }
    int q;
    cin >> q;
    vector<int> query(q);
    for (int i = 0; i < q; i++) {
        cin >> query[i];
    }

    auto check = [&](int x) {
        vector<int> arr(n);
        for (int i = 0; i < x; i++) {
            arr[query[i] - 1]++;
        }
        vector<int> psum(n + 1);
        for (int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + arr[i - 1];
        }
        bool ret = false;
        for (int i = 0; i < m; i++) {
            int l, r;
            tie(l, r) = range[i];
            l--;
            if ((psum[r] - psum[l]) * 2 > r - l) {
                ret = true;
            }
        }
        return ret;
    };

    int left = 0, right = q;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (left == q + 1)
        cout << -1 << '\n';
    else
        cout << left << '\n';
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
*적어두기, 구하고자 하는 것의 계층구조 표현하기.
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"(문제 알고리즘/특징의 "증명"으로 아이디어)
// {BruteForce, greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화 & 최적화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!
log(q)*(m + q)
*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 틀리면 느낌표 추가하기