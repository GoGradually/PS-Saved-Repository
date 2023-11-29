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
    vector<int> arr(n), want(n);
    vector<int> color(m);
    map<int, vector<int>> mustColoring;
    map<int, int> canOverlap, mustColoringIndex;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> want[i];
        if (arr[i] == want[i]) {
            canOverlap[arr[i]] = i + 1;
        } else {
            mustColoring[want[i]].push_back(i);
        }
    }
    vector<int> ans(m);
    stack<int> stk;
    for (int i = 0; i < m; i++) {
        cin >> color[i];
        if (mustColoringIndex[color[i]] == mustColoring[color[i]].size()) {
            if (mustColoringIndex[color[i]] == 0 && canOverlap[color[i]] == 0) {
                stk.push(i);
            } else {
                if (canOverlap[color[i]] != 0) {
                    ans[i] = canOverlap[color[i]] - 1;
                    while (!stk.empty()) {
                        ans[stk.top()] = ans[i];
                        stk.pop();
                    }
                } else {
                    ans[i] = mustColoring[color[i]].back();
                    while (!stk.empty()) {
                        ans[stk.top()] = ans[i];
                        stk.pop();
                    }
                }
            }
        } else {
            ans[i] = mustColoring[color[i]][mustColoringIndex[color[i]]++];
            while (!stk.empty()) {
                ans[stk.top()] = ans[i];
                stk.pop();
            }
        }
    }
    if (!stk.empty()) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mustColoring[i].size() != mustColoringIndex[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
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