#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, ll>> a;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        int val = 1;
        while (temp % m == 0) {
            val *= m;
            temp /= m;
        }
        if (a.empty() || a.back().first != temp) {
            a.push_back({temp, val});
        } else {
            a.back().second += val;
        }
    }
    int t;
    cin >> t;
    vector<pair<int, ll>> b;
    for (int i = 0; i < t; i++) {
        int temp;
        cin >> temp;
        int val = 1;
        while (temp % m == 0) {
            val *= m;
            temp /= m;
        }
        if (b.empty() || b.back().first != temp) {
            b.push_back({temp, val});
        } else {
            b.back().second += val;
        }
    }
    if (a.size() != b.size()) {
        cout << "No\n";
        return;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i].first != b[i].first || a[i].second != b[i].second) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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