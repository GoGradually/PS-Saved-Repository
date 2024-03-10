#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    ll n;
    cin >> n;
    ll left = 1, right = 3LL * INF;
    auto check = [&](ll val) -> bool {
        ll ans = 0;
        for (ll i = 2, j = 2; i * i - 1 <= val && i < 4; i++, j += 2) {
            ll start = i * i - 1;
            ll copied = val;
            copied -= start;
            ans += copied / j + 1;
        }
        if (ans < n)  // 모자를때
            return true;
        else
            return false;
    };
    while (left < right) {
        ll mid = (left + right) / 2;
        if (check(mid)) {  // 모자를때
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << left << '\n';
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
// 3. cutting | !구현(차근차근 단순화 & 최적화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!
1 4 9 16 25 36 49 64 81 100 121 144 169 225
3  5  7  9  11 13 15 17 19 21 23
8  12 16 20 24
15 21 27 33
24 32 40
35 45
48
특정 수 들어오면 그 수가 몇번째로 작은수인지 계산 가능
-> 루트nlogn
*/

// commit 시 피드백할 것 Message로 남겨두기!!