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
    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> space;
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            space.push_back(n - arr[m - 1] + arr[0] - 1);
        } else {
            space.push_back(arr[i] - arr[i - 1] - 1);
        }
    }
    sort(space.begin(), space.end());
    int ans = 0;
    int cnt = 0;
    for (int i = space.size() - 1; i >= 0; i--) {
        if (space[i] - 2 * cnt > 0) ans++;
        ans += max(0, space[i] - cnt - cnt - 2);
        cnt+=2;
    }
    cout << n - ans << '\n';
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
// 1. "추론" {greedy, D&C, DP, graph}(문제 특징의 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.

*/

// commit 시 피드백할 것 Message로 남겨두기!!