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
    vector<pair<int, int>> arr1(n), arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i].first;
        arr1[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i].first;
        arr2[i].second = i;
    }
    sort(arr1.begin(), arr1.end());
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (arr1[i].second != i) {
            ans.push_back({ i + 1, arr1[i].second + 1 });
            for (int j = 0; j < n; j++)
            {
                if (arr1[j].second == i) {
                    arr1[j].second = arr1[i].second;
                }
            }
            swap(arr2[i], arr2[arr1[i].second]);
        }
    }
    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n - 1; i++) {
            if (arr2[i].first > arr2[i + 1].first) {
                if (arr1[i].first == arr1[i + 1].first) {
                    ans.push_back({ i + 1, i + 2 });
                    swap(arr2[i], arr2[i + 1]);
                }
                else {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
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
// 1. "추론"(greedP, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"