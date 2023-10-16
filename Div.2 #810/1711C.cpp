#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int tempN = n, tempM = m;
    bool chance = false;
    for (int i = 0; i < k; i++) {
        if (arr[i] / m >= 2 && tempN >= 2) {
            tempN -= arr[i] / m;
            if (arr[i] / m > 2) chance = true;
        } else if (arr[i] / m >= 2 && tempN < 2) {
            if (chance) {
                tempN -= 1;
                break;
            }
        }
        if (tempN == 0) {
            break;
        }
    }
    if (tempN <= 0) {
        cout << "Yes\n";
        return;
    }
    chance = false;
    for (int i = 0; i < k; i++) {
        if (arr[i] / n >= 2 && tempM >= 2) {
            tempM -= arr[i] / n;
            if (arr[i] / n > 2) chance = true;
        } else if (arr[i] / n >= 2 && tempM < 2) {
            if (chance) {
                tempM -= 1;
                break;
            }
        }
        if (tempM == 0) {
            break;
        }
    }
    if (tempM <= 0) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
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
// 1. "추론" {greedy, D&C, DP, graph, math}(문제 특징의 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.

*/

// commit 시 피드백할 것 Message로 남겨두기!!
