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
    string s, t;
    cin >> s >> t;
    vector<pair<int, int>> sCount, tCount;
    for (int i = 0; i < n; i++) {
        if (sCount.empty() || sCount.back().first != s[i] - '0') {
            sCount.push_back({s[i] - '0', 1});
        } else {
            sCount.back().second++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (tCount.empty() || tCount.back().first != t[i] - '0') {
            tCount.push_back({t[i] - '0', 1});
        } else {
            tCount.back().second++;
        }
    }
    if (sCount.size() != tCount.size()) {
        cout << -1 << '\n';
        return;
    }
    if (sCount[0].first != tCount[0].first) {
        cout << -1 << '\n';
        return;
    }

    ll ans = 0;
    for (int i = 0; i < sCount.size(); i++) {
        if (sCount[i].second < tCount[i].second) {
            ll cnt = 1;
            while (true) {
                if (i + cnt == sCount.size()) {
                    cout << -1 << '\n';
                    return;
                }
                ll val = min(sCount[i + cnt].second - 1,
                             tCount[i].second - sCount[i].second);
                ans += val * cnt;
                sCount[i + cnt].second -= val;
                sCount[i].second += val;
                if (sCount[i].second == tCount[i].second) break;
                cnt++;
            }
        } else if (sCount[i].second > tCount[i].second) {
            ll val = sCount[i].second - tCount[i].second;
            if (i + 1 == sCount.size()) {
                cout << -1 << '\n';
                return;
            }
            sCount[i + 1].second += val;
            sCount[i].second -= val;
            ans += val;
        }
    }
    cout << ans << '\n';
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
// "처음"(ex: n=1) 부터 직접 경우의 수 전개 (수식/머릿속 시각화) +
// cutting + 그리디한 "추론"(증명 idea) -> 자료구조/알고리즘의 필요성 느끼기
// 늘려야 할 것 : 추론 + 직점 전개해서 코너케이스 찾는 능력 + 알고리즘 구현 능력