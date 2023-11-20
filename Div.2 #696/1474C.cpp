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
    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int t = 0; t < 2 * n; t++) {
        multiset<int> ms;
        for (int i = 0; i < 2 * n; i++) {
            if (i == t) continue;
            ms.insert(arr[i]);
        }
        vector<pair<int, int> > ans;
        int now = *ms.rbegin();
        ans.push_back({arr[t], now});
        ms.erase(ms.find(now));
        now = max(arr[t], now);
        while (!ms.empty()) {
            int next = *ms.rbegin();
            ms.erase(ms.find(next));
            if (ms.count(now - next) == 0) {
                break;
            }
            ms.erase(ms.find(now - next));
            ans.push_back({now - next, next});
            now = next;
        }
        if (ms.empty()) {
            cout << "YES\n";
            cout << ans[0].first + ans[0].second << '\n';
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].first << ' ' << ans[i].second << '\n';
            }
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
