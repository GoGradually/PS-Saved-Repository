#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> arr(n), v(k);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == i + 1) ans++;
    }
    ans += (d - 1) / 2;
    for (int i = 0; i < d - 1; i++) {
        if (n + (d - (i + 1)) / 2 <= ans) break;
        ll now = 0;
        for (int j = 0; j < v[i % k]; j++) {
            arr[j]++;
        }
        for (int j = 0; j < n; j++) {
            if (arr[j] == j + 1) now++;
        }
        now += (d - (i + 2)) / 2;
        ans = max(ans, now);
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
123456
012345
각 레벨에 맞춰
기대점수 계산해두기? -> 첫번째 상황만 계산에 유효하다.
근데 그 레벨이 vk값에 따라 미묘하게 달라지는데
값을 갱신하고 0의 개수 체크하는 방법
각 인덱스별로 가능한 구간이 나온다
그 구간은 반드시 맨 왼쪽이 제일 좁긴 한데
왼쪽을 버림으로써 최적의 해가 나오는 경우도 있음
그걸 IMOS법으로 가능 합이 최대가 나오는 구간 찾기? -> 구간 찾을때 2당 -1 계속
누적해가며 최대값 계산 n <= 2000 구간을 d번 순회가 아닌 공식으로 찾는 법- >이게
있으면 가능 세그먼트 트리로 j< v[t] 인  t 찾고 k * cnt(t) = left 되도록
세그트리로 하면 애매한 구간 계산이 어려워지긴 하는데
그냥 배열에 넣으면 안되나? -> 2억
시간복잡도 -> 2억 + 2천 + 2천
가능하긴 한데 애매하다
점수 최대 n+d/2점이 최대
초기화 전엔 n점이 최대?
0부터 시작
n까지
만약 n 다먹어도 더이상 이전 최댓값 못넘으면 볼 필요 없음
*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 출력해야 하는 값이 정확히 뭔지 파악하기, 한계 파악하기
// 거품 제한 걷어내기