#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

vector<int> g[200000];

void Solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }

    vector<ll> price(n);
    vector<ll> inDegree(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        price[--temp] = 0;
    }
    for (int i = 0; i < n; i++) {
        int count;
        cin >> count;
        if (price[i] != 0) inDegree[i] += count;
        for (int j = 0; j < count; j++) {
            int temp;
            cin >> temp;
            temp--;
            if (price[i] != 0) g[temp].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    vector<ll> craft(n, 0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto &&next : g[now]) {
            craft[next] += price[now];
            inDegree[next]--;
            if (inDegree[next] == 0) {
                q.push(next);
                price[next] = min(price[next], craft[next]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << price[i] << ' ';
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
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!
in-degree = 0 이 되면 내 진짜 가격 연산 가능
위상 정렬 느낌으로 전부 밑에서부터 트리DP 계산
*/

// commit 시 피드백할 것 Message로 남겨두기!!