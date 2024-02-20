#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    ll n, x;
    cin >> n >> x;
    int ans = 0;
    set<int> s;
    for (int i = 2; i * i < n - x; i += 2) {
        if (x <= (i + 2) / 2 && (n - x) % i == 0) {
            ans++;
        }
    }
    for (int i = 2; i * i < n + x - 2; i += 2) {
        if (x <= (i + 2) / 2 && (n + x - 2) % i == 0) {
            ans++;
        }
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

n%(2k - 2) <= k && x <= k && x != 0
n%(2k - 2) > k && 1 < x < k &&
if(x==0) x += n;

n자리 x 고정시켜두고
앞에 몇번 반복시킬것인가?
최대 n/2 번까지 계산해야함
k가 되면
앞자리 반복 기준
뒷자리 반복 기준
k     2 3 4 5 6  7  8
2k-2  2 4 6 8 10 12 14

(n-x) = (2k-2)t
(n+x-2) = (2k-2)*(t+1)



1. 모듈러 연산 % 그대로 놔두지 말고 임의의 음이 아닌 정수 * x 로 표현하기
2. 체계적인 상태를 유지하기
*/

// commit 시 피드백할 것 Message로 남겨두기!!