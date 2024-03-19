#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n;
    cin >> n;
    vector<ll> psum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }
    auto go = [&](int l, int r, ll u) {
        if (psum[r] - psum[l] <= u)
            return true;
        else
            return false;
    };

    int q;
    cin >> q;
    while (q--) {
        ll l, u;
        cin >> l >> u;
        int left = l;
        l--;
        int right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (go(l, mid, u)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        ll val = -lINF;
        ll ans = 0;
        for (int i = -2; i <= 2; i++) {
            int now = left + i;
            if (now <= l) continue;
            if (now > n) continue;
            ll nowVal = psum[now] - psum[l];
            ll rangeSum = (2LL * u - nowVal + 1) * nowVal / 2;
            if (rangeSum > val) {
                ans = now;
                val = rangeSum;
            }
        }
        cout << ans << ' ';
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
1. int 오버플로우, out of bounds
2. 특수한 경우(n=1?)
3. 잘못된 가정 & 증명

*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기, 구하고자 하는 것의 계층구조 표현하기.
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

x - u = 뒤
u - x = 앞
딱 맞추면 1 까지
오버되면 0부터

x 가 뭔데
x = 간 칸 수

x <= u
    u - x + 1 ~ u 까지
x > u
    x - u ~ u 까지

10 - 6 [5, 10]
10 - 14 [4, 10]
abs(x - u) + 1 =

*/

// commit 시 피드백할 것 Message로 남겨두기!!