#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int q;
    cin >> q;
    set<ll> archive;
    map<ll, ll> can;
    while (q--) {
        char tag;
        cin >> tag;
        if (tag == '+') {
            ll x;
            cin >> x;
            archive.insert(x);
        }
        if (tag == '?') {
            ll k;
            cin >> k;
            if (can[k] == 0) can[k] = k;
            while (true) {
                if (archive.find(can[k]) == archive.end()) {
                    break;
                }
                can[k] += k;
            }
            cout << can[k] << '\n';
        }
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
1. int 오버플로우, out of bounds
2. 특수한 경우(n=1?)
3. 잘못된 가정 & 증명

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
가장 작은 k의 배수 찾기
단, set에 없어야 함.

-> x가 set안에 들어가면
x의 약수들은 x를 못가져감.
약수를 찾는게 10억이네;
굳이 약수를 찾아야 할까?

최대 데이터 크기 nlogn->map 사용
근데 그럼 그 "가능한 값을 찾는 방법" 이 바뀌나?
가능한 값을 미리 저장해두는 맵 만들기
해당 맵이 0을 가리킨다 -> 자기자신 가능?x

*/

// commit 시 피드백할 것 Message로 남겨두기!!