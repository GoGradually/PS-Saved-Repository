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
    string str;
    cin >> str;
    vector<vector<pair<int, int>>> dp(n + 1,
                                      vector<pair<int, int>>(2, {INF, INF}));
    dp[2][0] = {str[0] - '0' + str[1] - '0', 1};
    dp[2][1] = {1 - (str[0] - '0') + 1 - (str[1] - '0'), 1};
    for (int i = 2; i < n; i += 2) {
        int c0, c1;
        c0 = str[i] - '0' + str[i + 1] - '0';
        c1 = 1 - (str[i] - '0') + 1 - (str[i + 1] - '0');
        dp[i + 2][0] =
            min(dp[i + 2][0], {dp[i][1].first + c0, dp[i][1].second + 1});
        dp[i + 2][0] =
            min(dp[i + 2][0], {dp[i][0].first + c0, dp[i][0].second});
        dp[i + 2][1] =
            min(dp[i + 2][1], {dp[i][0].first + c1, dp[i][0].second + 1});
        dp[i + 2][1] =
            min(dp[i + 2][1], {dp[i][1].first + c1, dp[i][1].second});
    }
    auto ans = min(dp[n][0], dp[n][1]);
    cout << ans.first << ' ' << ans.second << '\n';
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
// 1. 각 인덱스는 짝수개씩 묶여야 한다.
// 2. n개의 문자를 2개씩 묶어 생각할 수 있다.
// 3. 이전 블록의 색깔과 지금 바뀌었다면 하나 늘어난다.
초기조건 어떡하지? -> 때려박기
*/
