#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    string str;
    cin >> str;
    int val[2] = {0, 0};
    for (int i = 0; i < str.size(); i++) {
        val[str[i] - 'A']++;
    }
    if (val[0] != arr[0] + arr[2] + arr[3] || val[1] != arr[1] + arr[2] + arr[3]) {
        cout << "NO\n";
        return;
    }
    int cnt = 1;
    int pairCnt = 0, ABval = 0, BAval = 0;
    vector<int> ABCnt, BACnt;
    for (int i = 1; i < str.size(); i++) {
        if (str[i] != str[i - 1]) {
            cnt++;
        } else {
            if (cnt % 2 == 1) {
                arr[str[i - 1] - 'A']--;
                pairCnt += cnt / 2;
            } else {
                if (str[i] == 'A') {
                    BACnt.push_back({ cnt / 2 });
                    BAval += cnt / 2;
                } else {
                    ABCnt.push_back({ cnt / 2 });
                    ABval += cnt / 2;
                }
            }
            cnt = 1;
        }
    }
    if (cnt % 2 == 1) {
        arr[str[str.size() - 1] - 'A']--;
        pairCnt += cnt / 2;
    }
    else {
        if (str[str.size() - 1] == 'A') {
            BACnt.push_back({ cnt / 2 });
            BAval += cnt / 2;
        }
        else {
            ABCnt.push_back({ cnt / 2 });
            ABval += cnt / 2;
        }
    }
    sort(ABCnt.begin(), ABCnt.end(), greater<int>());
    sort(BACnt.begin(), BACnt.end(), greater<int>());
    int i = 0;
    while (i<ABCnt.size() && arr[2] < ABval) {
        arr[0]--;
        arr[1]--;
        pairCnt += ABCnt[i] - 1;
        ABval -= ABCnt[i];
        i++;
    }
    i = 0;
    while (i<BACnt.size() && arr[3] < BAval) {
        arr[0]--;
        arr[1]--;
        pairCnt += BACnt[i] - 1;
        BAval -= BACnt[i];
        i++;
    }
    if (arr[0] < 0 || arr[1] < 0) {
        cout << "NO\n";
    }
    else cout << "YES\n";
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
// 1. "추론"(greedP, 그 증명)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"