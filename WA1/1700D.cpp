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
    vector<ll> arr(n);
    vector<ll> dp(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        ll tag = (sum % (i + 1) == 0) ? 0 : 1;
        if (i == 0)
            dp[i] = sum / (i + 1) + tag;
        else
            dp[i] = max(dp[i - 1], sum / (i + 1) + tag);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        ll left = 1, right = n;
        auto check = [&](int sudo) {
            ll now = sum / sudo + ((sum % sudo != 0) ? 1 : 0);
            if (max(dp[sudo - 1], now) <= t) {
                return true;
            } else {
                return false;
            }
        };
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left > n)
            cout << -1 << '\n';
        else
            cout << left << '\n';
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
*아무것도 하지 않는 대신 무언가를 수행하고 체계적인 상태를 유지
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 문제의 "맥" 잡고있기, 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 예제 직접 전개(수식/머릿속 시각화) +
// cutting + 그리디한 "추론"(증명 idea) -> 자료구조/알고리즘의 필요성 느끼기