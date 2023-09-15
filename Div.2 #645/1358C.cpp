#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll ans = 0;
    ll x = x2 - x1, y = y2 - y1;
    if (x > y) swap(x, y);
    ans = x * (x - 1) + x + x * (y - x);
    cout << ans + 1 << '\n';
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
// 1. "추론"({greedy, D&C, DP, graph}, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"

/*
take notes.
서로 대칭인 경로의 합이 같은가
->대칭이면서 가운데 점을 지나는 경로
1  2  4  7
3  5  8  12
6  9  13 18
10 14 19 25
15 20 26 33
중점이 없으면 -> 그냥 곱하면 됨
중점 있으면? 다시 또 나눠서 방법 계산

최대 합 - 최소 합 + 1 이 정답
*/