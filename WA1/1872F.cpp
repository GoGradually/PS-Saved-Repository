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
    vector<int> arr(n);
    vector<ll> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    deque<int> ans;
    vector<bool> check(n, false);
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            vector<int> stk;
            int a = i, b = i;
            stk.push_back(a);
            a = arr[a];
            b = arr[arr[b]];
            bool visited = false;
            while (a != b) {
                if (check[a]) {
                    visited = true;
                    break;
                }
                stk.push_back(a);
                a = arr[a];
                b = arr[arr[b]];
            }
            if (check[a]) {
                visited = true;
            }
            if (visited) {
                while (!stk.empty()) {
                    check[stk.back()] = true;
                    ans.push_front(stk.back());
                    stk.pop_back();
                }
                continue;
            }
            a = i;
            while (a != b) {
                a = arr[a];
                b = arr[b];
            }
            int start = a;
            while (stk.back() != start) {
                stk.pop_back();
            }
            stk.pop_back();
            int minVal = cost[a];
            int minInd = a;
            a = arr[a];
            while (a != b) {
                if (cost[a] < minVal) {
                    minVal = cost[a];
                    minInd = a;
                }
                a = arr[a];
            }
            if (cost[a] < minVal) {
                minVal = cost[a];
                minInd = a;
            }
            a = arr[minInd];
            while (a != minInd) {
                stk.push_back(a);
                a = arr[a];
            }
            stk.push_back(minInd);
            for (int j = 0; j < stk.size(); j++) {
                check[stk[j]] = true;
                ans.push_back(stk[j]);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
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
//피드백: functional graph 의 floyd algorithm은 사이클에 진입하는 노드를 찾기 위한 용도!!!!!!!
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