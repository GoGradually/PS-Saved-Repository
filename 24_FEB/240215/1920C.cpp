#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

void Solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<int> dividable(1, 1);
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            dividable.push_back(i);
            if (n / i != i) {
                dividable.push_back(n / i);
            }
        }
    }
    sort(dividable.begin(), dividable.end());
    int ans = 1;

    for (int cnt = 0; cnt < dividable.size(); cnt++) {
        int k = dividable[cnt];
        int val = abs(arr[k] - arr[0]);
        for (int i = 0; i + k < n; i++) {
            val = gcd(val, abs(arr[i + k] - arr[i]));
        }
        if (val != 1) ans++;
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

약수의 개수(k) = logn
n번 순회
배열의 형태가 같으면 됨
a mod m == a+k mod m
 am + d == bm + d
a - a+k mod m = 0
|(a) - (a+k)| mod m = 0
같은 라인의 mod m 이 항상 0이도록
근데 m은 다른 라인도 항상 m으로 모듈로 되어야함
n * logn * logn

*/

// commit 시 피드백할 것 Message로 남겨두기!!