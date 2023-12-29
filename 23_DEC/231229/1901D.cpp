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
    vector<ll> arr(n);
    ll max_index = 0;
    ll max_value = 0;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        if (max_value < arr[i]) {
            max_value = arr[i];
            max_index = i;
        }
    }
    ll left = 0, right = lINF;
    auto f = [&](ll val) {
        bool ret = false;
        bool check = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] > val - i) {
                check = false;
            }
        }
        if (check) ret = true;
        check = true;
        for (int i = 0; i < n; i++) {
            if (arr[n - 1 - i] > val - i) {
                check = false;
            }
        }
        if (check) ret = true;
        check = true;

        for (int i = 0; i < n; i++) {
            if (i < max_index) {
                if (arr[i] > val - (n - i - 1)) {
                    check = false;
                }
            } else if (i > max_index) {
                if (arr[i] > val - i) {
                    check = false;
                }
            } else {
                if (arr[i] > val) {
                    check = false;
                }
            }
        }

        if (check) ret = true;
        return ret;
    };
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (f(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << left << '\n';
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
// 1. "추론"(문제 특징의 "증명"으로 아이디어){greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.
최댓값, 최댓값 왼쪽, 최댓값 오른쪽
*/

// commit 시 피드백할 것 Message로 남겨두기!!