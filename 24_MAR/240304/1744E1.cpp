#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void Solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ab = a * b;
    for (ll x = a + 1; x <= c; x++) {
        ll gcdabx = gcd(ab, x);
        ll val = ab / gcdabx;
        ll y = d / val * val;
        if (y > b) {
            cout << x << ' ' << y << '\n';
            return;
        }
    }
    cout << -1 << ' ' << -1 << '\n';
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
인수분해하면 log(a*b)개
27개니까 완탐?
더 커지긴 해야함
a약수 하나 빼고 더 큰수 곱하면 x > a
"더 큰수"의 정의가 너무 넓다?

역으로 a*b*t <= c*d 인 모든 값 확인?
어떻게 분배하지?
최대한 작게 하고 반대쪽에 몰빵? 완탐은 시복 무조건 터짐.
0. a<x<=c
1. xy 는 ab에 나누어 떨어진다
2. 그렇다는 것은 y는 ab / x 한 값의 배수이다.
3. ab/x = ab/gcd(ab, x)/x/gcd(ab,x)



*/

// commit 시 피드백할 것 Message로 남겨두기!!