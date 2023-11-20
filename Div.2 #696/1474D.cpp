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
    vector<ll> arr(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<ll> prefix(n + 2), suffix(n + 2);
    for (int i = 1; i <= n; i++) {
        if (prefix[i - 1] < 0) {
            prefix[i] = prefix[i - 1];
            continue;
        }
        prefix[i] = arr[i] - prefix[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        if (suffix[i + 1] < 0) {
            suffix[i] = suffix[i + 1];
            continue;
        }
        suffix[i] = arr[i] - suffix[i + 1];
    }

    for (int i = 0; i <= n; i++) {
        if (prefix[i] < 0 || suffix[i + 1] < 0) continue;
        if (prefix[i] == suffix[i + 1]) {
            cout << "YES\n";
            return;
        }
    }
    for (int i = 0; i <= n - 2; i++) {
        if (prefix[i] < 0 || suffix[i + 3] < 0) continue;
        if (arr[i + 2] - prefix[i] < 0) continue;
        if (arr[i + 2] - prefix[i] == arr[i + 1] - suffix[i + 3]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
// 1. "추론"(문제 특징의 "증명"으로 아이디어){greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.

*/

// commit 시 피드백할 것 Message로 남겨두기!!