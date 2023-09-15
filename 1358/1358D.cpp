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
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr.push_back(arr[i]);
    }
    vector<ll> psum(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
        psum[i + 1] = psum[i] + arr[i];
    }

    int left = 0, right = 0;
    ll val = 0;
    ll ans = 0;
    while (right < 2 * n) {
        if (psum[right] - psum[left] > x) {
            ll remain = psum[right] - psum[left] - x;
            ll val2 = val - arr[right - 1] * (arr[right - 1] + 1) / 2;
            val2 += (arr[right-1] - remain) * (arr[right-1] - remain + 1) / 2;
            ans = max(ans, val2);
            while (psum[right] - psum[left] > x) {
                val -= arr[left] * (arr[left] + 1) / 2;
                left++;
            }
            ll temp = arr[left - 1];
            val2 = val + temp * (temp + 1) / 2;
            temp = psum[right] - psum[left] + temp - x;
            val2 -= (temp + 1) * temp / 2;
            ans = max(val2, ans);
        } else {
            val += arr[right] * (arr[right] + 1) / 2;
            right++;
        }
    }
    if (psum[right] - psum[left] > x) {
        ll remain = psum[right] - psum[left] - x;
        ll val2 = val - arr[right - 1] * (arr[right - 1] + 1) / 2;
        val2 += (arr[right - 1] - remain) * (arr[right - 1] - remain + 1) / 2;
        ans = max(ans, val2);
        while (psum[right] - psum[left] > x) {
            val -= arr[left] * (arr[left] + 1) / 2;
            left++;
        }
        ll temp = arr[left - 1];
        val2 = val + temp * (temp + 1) / 2;
        temp = psum[right] - psum[left] + temp - x;
        val2 -= (temp + 1) * temp / 2;
        ans = max(val2, ans);
    }
    cout << ans << '\n';
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
// 1. "추론"({greedy, D&C, DP, graph}, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"

/*
take notes.
n 8
1 2 3 4 1 2 3 4 1 1 1 1 1 1 1 1 2 3 4 5 1 1 1 1 1 1 1
여기를 시작으로 하는/여기를 끝으로 하는
투 포인터?
줄이기 전 좌 우 계산 후 줄이기
좌측 끝은 마지막에 right에서 바뀐거니 계산하기 쉬운데
우측 끝은 어떻게 계산하지?
어차피 left 당겨야 하니
left 위치 조정하고 깔끔하게 계산하자
*/