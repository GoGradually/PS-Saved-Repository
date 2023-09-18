#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    set<int> one, two, three;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1') one.insert(i);
        if (str[i] == '2') two.insert(i);
        if (str[i] == '3') three.insert(i);
    }
    int ans = INF;
    for (int i = 0; i < str.size(); i++) {
        int mx = 0;
        if (one.lower_bound(i) != one.end())
            mx = max(mx, *one.lower_bound(i) - i + 1);
        else
            mx = INF;
        if (two.lower_bound(i) != two.end())
            mx = max(mx, *two.lower_bound(i) - i + 1);
        else
            mx = INF;
        if (three.lower_bound(i) != three.end())
            mx = max(mx, *three.lower_bound(i) - i + 1);
        else
            mx = INF;
        ans = min(mx, ans);
    }
    if (ans == INF)
        cout << 0 << '\n';
    else
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
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"({greedy, D&C, DP, graph}, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"

/*
take notes.


*/
