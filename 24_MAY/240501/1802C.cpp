#include <bits/stdc++.h>
#define ll long long
#define INF ((int)1e9 + 10)
#define lINF ((ll)1e18 + 10LL)
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, m;
    cin >> n >> m;
    cout << n * m << '\n';
    vector<vector<ll>> arr(n + 15, vector<ll>(m + 15));

    vector<int> prev_perm(16, 0);
    ll cnt = 0;
    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j <= m / 2; j++) {
            arr[i * 2][j * 2] = cnt;
            arr[i * 2][j * 2 + 1] = cnt + 1;
            arr[i * 2 + 1][j * 2] = cnt + 2;
            arr[i * 2 + 1][j * 2 + 1] = cnt + 3;
            cnt += 4;
        }
        cnt -= 4 * (m / 2 + 1);
        cnt += (1 << 20);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
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
// 3. 가장 Naive한 알고리즘부터 시작하기 (완전 탐색, 단순 자료구조)
// 4. cutting | 구현(차근차근 단순화 & 최적화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

n < 200
m < 200
2 ^ 16 = 6만

*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 틀리면 느낌표 추가하기