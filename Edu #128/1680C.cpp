#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    string str;
    cin >> str;
    int n = str.size();
    int cnt = 0;
    vector<int> remainPost0(n + 2);
    for (int i = 0; i < n; i++)
    {
        if (str[i] - '0' == 0)cnt++;
    }
    for (int i = n; i > 0; i--) {
        remainPost0[i] = remainPost0[i + 1];
        if (str[i - 1] - '0' == 0) {
            remainPost0[i]++;
        }
    }
    vector<int> erasedPre1(n + 2);
    for (int i = 1; i <= n; i++) {
        erasedPre1[i] = erasedPre1[i - 1] + ((str[i - 1] - '0' == 1) ? 1 : 0);
    }
    vector<int> erasedPost1(n + 2);
    for (int i = n; i > 0; i--) {
        erasedPost1[i] = erasedPost1[i + 1] + ((str[i - 1] - '0' == 1) ? 1 : 0);
    }

    int ans = INF;
    auto check = [&](int x, int alpha, int beta) {
        if (alpha - remainPost0[x] >= beta + erasedPost1[x])
            return true;
        else
            return false;
    };
    auto binary_search = [&](int left, int right, int alpha, int beta) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid, alpha, beta)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    };
    for (int i = 0; i <= n; i++) {
        int alpha = remainPost0[i + 1];
        int beta = erasedPre1[i];
        int x = binary_search(i + 1, n + 1, alpha, beta);
        if (ans > max(cnt - alpha - remainPost0[x], beta + erasedPost1[x])) {
            ans = max(cnt - alpha - remainPost0[x], beta + erasedPost1[x]);
        }
        if (x <= n && ans > max(alpha - remainPost0[x + 1],
            beta + erasedPost1[x + 1])) {
            ans = min(ans, max(alpha - remainPost0[x + 1],
                beta + erasedPost1[x + 1]));
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
 *찾아야 할 것들
 *int 오버플로우, out of bounds
 *특수한 경우(n=1?)
 *아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
 *적어두기
 *한가지 접근 방식에 얽메이지 말기
 */
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"({greedy, D&C, DP, graph}, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"