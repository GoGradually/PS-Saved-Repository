#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, c, q;
    string str;
    cin >> n >> c >> q >> str;
    vector<pair<ll, ll>> command;
    command.push_back({1, n});
    for (int i = 0; i < c; i++) {
        ll a, b;
        cin >> a >> b;
        command.push_back({a, b});
    }
    auto beforeRange = [&](ll k) {
        int index = 0;
        while (k - (command[index].second - command[index].first + 1) > 0) {
            k -= (command[index].second - command[index].first + 1);
            index++;
        }
        return command[index].first + k - 1;
    };
    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        int index = 0;
        ll beforek = -1;
        while (beforek != k) {
            beforek = k;
            k = beforeRange(k);
        }
        cout << str[k - 1] << '\n';
    }
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
// 문제의 "맥" 잡고있기, 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// "처음" 부터 직접 경우의 수 전개 (수식/머릿속 시각화) +
// cutting + 그리디한 "추론"(증명 idea) -> 자료구조/알고리즘의 필요성 느끼기