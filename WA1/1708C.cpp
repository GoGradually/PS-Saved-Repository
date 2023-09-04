#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    auto f = [&](ll val) {
        int now = q;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= now) {
                ret += 1;
            } else {
                if (i >= val) {
                    now--;
                    ret += 1;
                } else
                    ret += 0;
            }
        }
        return now >= 0;
    };
    ll lo = 0, hi = n - 1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (f(mid))
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    int val = hi + 1;
    int mx = 0;
    string ans;
    int now = q;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= now) {
            ans += '1';
        } else {
            if (now > 0 && i >= val) {
                now--;
                ans += '1';
            } else
                ans += '0';
        }
    }
    cout << ans << '\n';

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
    // 1. "추론"({greedy, DP, graph}, 증명으로 아이디어)
    // 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
    // 3. "구현"