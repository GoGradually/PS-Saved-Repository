#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(k, vector<int>(n));
    vector<int> now(k, 1);
    vector<bool> ok(k, true);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    if (k == 1) {
        cout << "YES\n";
        return;
    }
    for (int tt = 0; tt < n; tt++) {
        map<int, vector<int>> mp;
        set<int> s;
        for (int i = 0; i < k; i++) {
            if (now[i] >= n) {
                if (ok[i]) {
                    mp[arr[i][0]].push_back(i);
                    s.insert(arr[i][0]);
                } else {
                    cout << "NO\n";
                    return;
                }
            } else {
                mp[arr[i][now[i]]].push_back(i);
                s.insert(arr[i][now[i]]);
            }
        }

        vector<int> num;
        for (auto&& i : s) {
            num.push_back(i);
        }
        if (num.size() > 2) {
            cout << "NO\n";
            return;
        }
        if (num.size() == 1) {
            for (int i = 0; i < k; i++) {
                now[i]++;
            }
            continue;
        }
        if (mp[num[0]].size() == 1) {
            // 1번 나온 사람의 0번째 인덱스의 값이 n번나온 값과 같다면
            if (ok[mp[num[0]][0]] && arr[mp[num[0]][0]][0] == num[1]) {
                for (int i = 0; i < k; i++) {
                    if (i == mp[num[0]][0]) continue;
                    now[i]++;
                }
                ok[mp[num[0]][0]] = false;
                continue;
            }
        }
        if (mp[num[1]].size() == 1) {
            // 1번 나온 사람의 0번째 인덱스의 값이 n번나온 값과 같다면
            if (ok[mp[num[1]][0]] && arr[mp[num[1]][0]][0] == num[0]) {
                for (int i = 0; i < k; i++) {
                    if (i == mp[num[1]][0]) continue;
                    now[i]++;
                }
                ok[mp[num[1]][0]] = false;
                continue;
            }
        }

        cout << "NO\n";
        return;
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

1 3 5 2 6 4
6 3 5 2 1 4
막막할떈 {greedy, D&C, DP, graph, math} 하나씩 무조건 대입해보기
*/

// commit 시 피드백할 것 Message로 남겨두기!!