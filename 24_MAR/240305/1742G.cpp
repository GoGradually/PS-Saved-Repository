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
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = arr[i].first;
    }
    ll now = 0;
    vector<ll> ans;
    while (true) {
        sort(arr.begin(), arr.end());
        if (arr.size() == 0 || arr[arr.size() - 1].first == 0) break;
        ans.push_back(arr[arr.size() - 1].second);
        now |= arr[arr.size() - 1].first;
        arr.pop_back();
        for (int i = 0; i < arr.size(); i++) {
            arr[i].first &= (~now);
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        ans.push_back(arr[i].second);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
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
*한가지 접근 방식에 얽메이지 말기 -> 다양한 각도로 접근하기
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

가장 큰 비트부터
큰 비트 채워지면 그 다음비트 채우는거 먼저
만약 둘이 MSB가 같다면 그 다음 MSB순
가장 큰 수 있으면 걔는 무조건 맞나?
그걸 제거하게 되면 매번 우선순위가 바뀜 -> 시간복잡도 폭발
문제는 하나를 선택하면 나머지 전체의 정보가 바뀌는 것.
32 * 20만개의 배열해도 아래에서 정보가 바뀌어서 최대값이 최적이 아님
모든 값은 32칸 안에 최적해를 찾는다는 것에 집중해보자

*/

// commit 시 피드백할 것 Message로 남겨두기!!