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
    vector<vector<ll>> arr(2, vector<ll>(26, 0));
    arr[0][0] = 1;
    arr[1][0] = 1;
    while (q--) {
        ll tag, k;
        string x;
        cin >> tag >> k >> x;
        tag--;
        for (int i = 0; i < x.size(); i++) {
            arr[tag][x[i] - 'a'] += k;
        }
        int left = 0;
        int right = 25;
        while (arr[0][left] == 0) left++;
        while (arr[1][right] == 0) right--;
        if (left < right) {
            cout << "YES\n";
        } else if (left > right) {
            cout << "NO\n";
        } else {
            ll l_remain = 0;
            ll l_cnt = arr[0][left];
            ll r_remain = 0;
            ll r_cnt = arr[1][right];
            left++;
            right--;
            while (left < 26) l_remain += arr[0][left++];
            while (right >= 0) r_remain += arr[1][right--];
            if (l_remain == 0 && r_remain == 0) {
                if (l_cnt < r_cnt)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            } else if (l_remain == 0) {
                if (l_cnt <= r_cnt)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            } else if (r_remain == 0) {
                cout << "NO\n";
            } else {
                cout << "NO\n";
            }
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
// 1. "추론"(문제 특징의 "증명"으로 아이디어){greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!
앞 배열은 a부터
뒷 배열은 z부터

cccdd
cccccbb !

cccdd
cccbb !

cccccdd
cccbb !

----------------
ccc !
cccccbb

ccc !
cccbb

ccc
cbb !

------------------

cccdd
cc !

cccdd
ccc !

cccdd
cccc !
-------------
ccc !
cccc

ccc
ccc !

ccc
cc !
같고 같으면 ->
    -
*/

// commit 시 피드백할 것 Message로 남겨두기!!