#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;
vector<tuple<int, ll, ll>> g[200001];
void Solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> check(n + 1, {-lINF, -lINF});
    for (int i = 0; i < m; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        g[a].push_back({b, x, y});
        g[b].push_back({a, -x, -y});
    }
    queue<int> bfsQ;
    bfsQ.push(1);
    check[1] = {0, 0};
    vector<bool> ok(n + 1, true);
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        if (!ok[now])continue;
        for (auto &&next : g[now]) {
            int p;
            ll x, y;
            tie(p, x, y) = next;
            if (check[p].first == -lINF && check[p].second == -lINF ) {
                bfsQ.push(p);
                check[p] = {check[now].first + x, check[now].second + y};
            } else if (check[p].first !=
                       check[now].first + x || check[p].second != check[now].second + y) {
                ok[p] = false;

            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (check[i].first == -lINF) {
            ok[i] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        if(ok[i])cout << check[i].first << ' ' << check[i].second << '\n';
        else
            cout << "undecidable\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
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