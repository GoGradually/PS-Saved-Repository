#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> merchandiser(m);
    for (int i = 0; i < m; i++) {
        cin >> merchandiser[i];
    }
    ll ans = 0;
    ll val = 0;
    ll cnt = 1;
    if (merchandiser[0] != 1)
        merchandiser.push_back(1);
    else
        ans++;
    sort(merchandiser.begin(), merchandiser.end());
    for (int i = 1; i < merchandiser.size(); i++) {
        cnt += (merchandiser[i] - merchandiser[i - 1]) / d;
        if ((merchandiser[i] - merchandiser[i - 1]) % d != 0) cnt++;
    }
    cnt += (n - merchandiser.back()) / d;

    for (int i = 1; i < merchandiser.size(); i++) {
        if (i == merchandiser.size() - 1) {
            ll a = (merchandiser[i] - merchandiser[i - 1]) / d;
            if ((merchandiser[i] - merchandiser[i - 1]) % d != 0) a++;
            a += (n - merchandiser[i]) / d;
            ll b = (n - merchandiser[i - 1]) / d;
            if (val > b - a) {
                val = b - a;
                ans = 1;
            } else if (val == b - a) {
                ans++;
            }
        } else {
            ll a = (merchandiser[i] - merchandiser[i - 1]) / d;
            if ((merchandiser[i] - merchandiser[i - 1]) % d != 0) a++;
            a += (merchandiser[i + 1] - merchandiser[i]) / d;
            if ((merchandiser[i + 1] - merchandiser[i]) % d != 0) a++;
            ll b = (merchandiser[i + 1] - merchandiser[i - 1]) / d;
            if ((merchandiser[i + 1] - merchandiser[i - 1]) % d != 0) b++;
            if (val > b - a) {
                val = b - a;
                ans = 1;
            } else if (val == b - a) {
                ans++;
            }
        }
    }
    cout << cnt + val << ' ' << ans << '\n';
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
*아무것도 하지 않는 대신 무언가를 수행하고 체계적인 상태를 유지
*적어두기
*한가지 접근 방식에 얽메이지 말기
// 문제의 "맥" 잡고있기, 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 예제 직접 전개(수식/머릿속 시각화) &
// 그리디한 "추론"(증명 idea)-> -자료구조/알고리즘의 필요성 느끼기
*/