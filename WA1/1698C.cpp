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
    vector<ll> zero, pos, neg;
    map<ll, bool> ok;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ok[arr[i]] = true;
        if (arr[i] > 0) pos.push_back(arr[i]);
        if (arr[i] < 0) neg.push_back(arr[i]);
        if (arr[i] == 0 && zero.size() < 2) zero.push_back(arr[i]);
    }
    if (pos.size() > 2 || neg.size() > 2) {
        cout << "NO\n";
        return;
    }
    vector<ll> ans;
    for (int i = 0; i < pos.size(); i++) {
        ans.push_back(pos[i]);
    }
    for (int i = 0; i < neg.size(); i++) {
        ans.push_back(neg[i]);
    }
    for (int i = 0; i < zero.size(); i++) {
        ans.push_back(0);
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = i + 1; j < ans.size(); j++) {
            for (int k = j + 1; k < ans.size(); k++) {
                if (!ok[ans[i] + ans[j] + ans[k]]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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
*아무것도 하지 않는 대신 무언가를 수행하고 체계적인 상태를 유지
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 문제의 "맥" 잡고있기, 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 예제 직접 전개(수식/머릿속 시각화) +
// cutting + 그리디한 "추론"(증명 idea) -> 자료구조/알고리즘의 필요성 느끼기