#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) s.insert(i);
    }
    while (q--) {
        int tag;
        cin >> tag;
        if (tag == 1) {
            int val;
            cin >> val;
            if (s.size() == 0) {
                if (val <= n * 2 && val % 2 == 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
                continue;
            }
            int s1 = n * 2 - s.size();
            int s2 = max(n * 2 - (*s.begin()) * 2 - 1,
                         n * 2 - (n - (*s.rbegin())) * 2 - 1);
            if (val % 2 == s1 % 2) {
                if (val <= s1)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            } else if (val % 2 == s2 % 2) {
                if (val <= s2)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        } else {
            int index, change;
            cin >> index >> change;
            if (arr[index - 1] == change) continue;
            if (change == 1) {
                s.insert(index - 1);
            } else {
                s.erase(s.find(index - 1));
            }
        }
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
패리티는 무조건 맞출 수 있다
패리티 1일때 max값과
패리티 0일때 max값 계산해두기
가장 가까운 1의 위치가
반대 패리티의 max값 결정한다?
최댓값 저장하는 방법
우선순위큐를 이용한다?전체 부호가 달라진다
기존 max가 반대편 max로 이동하고
반대편 max는 새로 계산되는데

set을 이용한 count 하여 최댓값에 빼서 계산하는 구현
*/

// commit 시 피드백할 것 Message로 남겨두기!!