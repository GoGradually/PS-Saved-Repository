#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll penalty = 0;
    ll ans = 0;
    ll val = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            ll newPenalty = d * (i + 1);
            ll newVal = val + arr[i];
            if (pq.size() == m) newVal -= pq.top();
            val = newVal;
            penalty = newPenalty;
            if (pq.size() == m) pq.pop();
            pq.push(arr[i]);
        }
        ans = max(ans, val - penalty);
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
자릿수는 필요없다
m과 n만 있으면 된다?
n^2
그리디하게 적용이 되나?
무조건 앞에서 m번 방문한건 고정
마지막 방문과의 거리
이득을 볼 수 있는 타이밍은 무조건 봐야하나? 더 효율좋은 쪽이 뒤에 있을수도
2^200000
최댓값 기준이 날 포함한 최댓값 기준으로 잡아야 한다.
그럼 그 분기들을 전부 계산을 해봐야 한다.
이걸 뭉치는 방법
-> 각 인덱스별 내가 쌓은 값보다 깎는 값이 더 커지는 범위
    이건 확정이다 ? 아예 안하는거보단 무조건 이득일텐데

누적합으로 분리? -d -d x=0 -d -d -d -d x=0
시간별로 데이터가 깎이니까
1. 문제 알고리즘, 특징의 증명으로 아이디어 찾아야 한다.
2. 분기 경우의 수 직접 전개
2가지 조건
박힌돌이 이득
기존돌이 이득
*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 틀리면 느낌표 추가하기