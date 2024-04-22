#include <bits/stdc++.h>
#define ll long long
#define INF ((int)1e9 + 10)
#define lINF ((ll)1e18 + 10LL)
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n;
    string str;
    cin >> n >> str;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[str[i] - 'a']++;
    }
    if (n % 2 == 1) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > n / 2) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<int> same(26);
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (str[i] == str[n - 1 - i]) {
            same[str[i] - 'a']++;
        }
    }
    sort(same.begin(), same.end());
    int sum = 0;
    for (int i = 0; i < 25; i++) {
        sum += same[i];
    }
    if (sum < same[25]) {
        ans = same[25];
    } else {
        ans = (same[25] + sum + 1) / 2;
    }
    cout << ans << '\n';
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
홀수 -1 확정
한 글자가 전체 글자의 절반 초과이면 -1 확정
최소 작업 횟수?
*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 틀리면 느낌표 추가하기