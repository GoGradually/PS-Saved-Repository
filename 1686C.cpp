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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n % 2 == 1) {
        cout << "NO\n";
        return;
    }
    sort(arr.begin(), arr.end());
    vector<int> ans1, ans2;
    int left = 0, right = n/2;
    while (right < n) {
        ans1.push_back(arr[left]);
        ans1.push_back(arr[right]);
        ans2.push_back(arr[right++]);
        ans2.push_back(arr[left++]);
    }
    bool ok1 = true, ok2 = true;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            if (!(ans1[i] > ans1[(i - 1 + n) % n] &&
                  ans1[i] > ans1[(i + 1 + n) % n])) {
                ok1 = false;
            }
            if (!(ans2[i] < ans2[(i - 1 + n) % n] &&
                ans2[i] < ans2[(i + 1 + n) % n])) {
                ok2 = false;
            }
        } else {
            if (!(ans1[i] < ans1[(i - 1 + n) % n] &&
                  ans1[i] < ans1[(i + 1 + n) % n])) {
                ok1 = false;
            }
            if (!(ans2[i] > ans2[(i - 1 + n) % n] &&
                ans2[i] > ans2[(i + 1 + n) % n])) {
                ok2 = false;
            }
        }
    }
    if (ok1) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << ans1[i] << ' ';
        }
    }
    else if (ok2) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << ans2[i] << ' ';
        }

    }
    else {
        cout << "NO";
    }
    cout << '\n';
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
// 1. "추론"(greedp, 그 증명)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"