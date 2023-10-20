#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    ll ans = 0;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
        if (i > 0) ans += abs(arr[i] - arr[i - 1]);
    }
    int oneVal = INF;
    int xVal = INF;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            oneVal = min(oneVal, abs(arr[i] - 1));
            xVal = min(xVal, abs(arr[i] - x));
        } else if (i == n) {
            oneVal = min(oneVal, abs(arr[i - 1] - 1));
            xVal = min(xVal, abs(arr[i - 1] - x));
        } else {
            oneVal = min(oneVal, 2 * abs(min(arr[i], arr[i - 1]) - 1));
            xVal = min(xVal, 2 * abs(max(arr[i], arr[i - 1]) - x));
        }
    }
    if (x < maxVal) xVal = 0;
    cout << ans + oneVal + xVal << '\n';
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
// 1. "추론" {greedy, D&C, DP, graph, math}(문제 특징의 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.

*/

// commit 시 피드백할 것 Message로 남겨두기!!
