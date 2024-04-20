#include <bits/stdc++.h>
#define ll long long
#define INF ((int)1e9 + 10)
#define lINF ((ll)1e18 + 10LL)
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

vector<int> g[200001];

void Solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        temp--;
        g[temp].push_back(i);
    }
    int cnt = 0;
    int halfCnt = 0;
    queue<int> bfsQ;
    vector<int> check(n);
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 2) {
            int next1 = g[i][0];
            int next2 = g[i][1];
            if (check[next1] == 1 || check[next2] == 1) continue;
            halfCnt++;

            bfsQ.push(i);
            check[i] = 1;
        } else if (g[i].size() == 1) {
            if (g[g[i][0]].size() == 1 && g[g[i][0]][0] == i) {
                if (check[g[i][0]] == 1) continue;
                halfCnt++;
                bfsQ.push(i);
                check[i] = 1;
            }
        }
    }

    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        for (int i = 0; i < g[now].size(); i++) {
            int next = g[now][i];
            if (check[next] == 0) {
                check[next] = 1;
                bfsQ.push(next);
            }
        }
    }
    for (int t = 0; t < n; t++) {
        if (check[t] == 0) {
            check[t] = 1;
            bfsQ.push(t);
            cnt++;
            while (!bfsQ.empty()) {
                int now = bfsQ.front();
                bfsQ.pop();
                for (int i = 0; i < g[now].size(); i++) {
                    int next = g[now][i];
                    if (check[next] == 0) {
                        check[next] = 1;
                        bfsQ.push(next);
                    }
                }
            }
        }
    }
    cout << cnt + (halfCnt ? 1 : 0) << ' ' << cnt + halfCnt << '\n';
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
1. int 오버플로우, out of bounds
2. 특수한 경우(n=1?)
3. 잘못된 가정 & 증명

*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기, 구하고자 하는 것의 계층구조 표현하기.
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"(문제 알고리즘/특징의 "증명"으로 아이디어)
// {BruteForce, greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화 & 최적화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 틀리면 느낌표 추가하기