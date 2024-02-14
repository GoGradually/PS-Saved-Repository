#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    ll x, y, p, q, r, s;
    cin >> x >> y >> p >> q >> r >> s;
    if (r - p <= 0) {
        cout << "Draw\n";
        return;
    }
    if ((r - p) % 2 == 1) {
        if (q > s)
            p += 2 * (min(s - 1, (r - p) / 2));
        else
            p += 2 * (min(y - s, (r - p) / 2));
        if (r - p >= abs(q - s)* 2 - 1) {
            cout << "Alice\n";
            return;
        }
    } else {
        if (q < s)
            r -= 2 * (min(q - 1, (r - p) / 2));
        else
            r -= 2 * (min(y - q, (r - p) / 2));
        if (r - p >= abs(q - s)*2) {
            cout << "Bob\n";
            return;
        }
    }
    cout << "Draw\n";
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
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!
1 0 0 0
0 0 0 0
0 0 0 0
0 0 0 2

*/

// commit 시 피드백할 것 Message로 남겨두기!!