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
    string str;
    cin >> str;
    vector<pair<int, int>> arr;
    arr.push_back({str[0] - '0', 1});
    for (int i = 1; i < n; i++) {
        if (str[i] - '0' == arr.back().first)
            arr.back().second++;
        else
            arr.push_back({str[i] - '0', 1});
    }
    int t = arr.size();
    bool tag = false;
    int cnt[2] = {0, 0};
    int check = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (!tag && arr[i].second % 2 == 1) {
            tag = true;
            check = 0;
            cnt[0] = 0;
            cnt[1] = 0;
            cnt[arr[i].first] += arr[i].second;
        } else if (tag && arr[i].second % 2 == 1) {
            cnt[arr[i].first] += arr[i].second;
            check++;
            tag = false;
        } else if (tag && arr[i].second % 2 == 0) {
            cnt[arr[i].first] += arr[i].second;
            check++;
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
// 1. "추론"({greedy, D&C, DP, graph}, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"