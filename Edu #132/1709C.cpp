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
    if (str.size() % 2 == 1) {
        cout << "NO\n";
        return;
    }
    int n = str.size();
    vector<int> prequote(n), pre(n), sufquote(n), suf(n);
    for (int i = 0; i < n; i++) {
        if (i == 0)
            prequote[i] = (str[i] == '?') ? 1 : 0;
        else
            prequote[i] = prequote[i - 1] + ((str[i] == '?') ? 1 : 0);
        if (i == 0) {
            if (str[i] == '(')
                pre[i] = 1;
            else if (str[i] == ')')
                pre[i] = -1;
        } else {
            if (str[i] == '(')
                pre[i] = pre[i - 1] + 1;
            else if (str[i] == ')')
                pre[i] = pre[i - 1] - 1;
            else
                pre[i] = pre[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1)
            sufquote[i] = (str[i] == '?') ? 1 : 0;
        else
            sufquote[i] = sufquote[i + 1] + ((str[i] == '?') ? 1 : 0);
        if (i == n - 1) {
            if (str[i] == ')')
                suf[i] = 1;
            else if (str[i] == '(')
                suf[i] = -1;
        } else {
            if (str[i] == ')')
                suf[i] = suf[i + 1] + 1;
            else if (str[i] == '(')
                suf[i] = suf[i + 1] - 1;
            else
                suf[i] = suf[i + 1];
        }
    }
    int fixed = 0;
    for (int i = -1; i < n; i++) {
        int prefix = (i >= 0) ? pre[i] : 0;
        int prefixQuote = ((i >= 0) ? prequote[i] : 0);
        int suffix = (i < n - 1) ? suf[i + 1] : 0;
        int suffixQuote = (i < n - 1) ? sufquote[i + 1] : 0;
        int rightMax = suffix + suffixQuote;
        int rightMin = suffix - suffixQuote;
        if (rightMin < 0) {
            rightMin *= -1;
            rightMin %= 2;
        }
        int leftMax = prefix + prefixQuote;
        int leftMin = (prefix - prefixQuote);
        if (leftMin < 0) {
            leftMin *= -1;
            leftMin %= 2;
        }
        if (leftMax < rightMin || rightMax < leftMin) {
            cout <<1<< "NO\n";
            return;
        }
        if (leftMax >= rightMin && leftMax <= rightMax) {
            if (leftMax - max(leftMin, rightMin) > 1) {
                cout << 2 <<i<< "NO\n";
                return;
            }
        }
        if (rightMax >= leftMin && rightMax <= leftMax) {
            if (rightMax - max(leftMin, rightMin) > 1) {
                cout << 3 << "NO\n";
                return;
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
*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"({greedy, D&C, DP, graph}, 특징 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"

/*
take notes.
여러 방법이 있으면 or 불가능하면 false
유일하면 true;
트리로 모든 방법을 알아보게 될 경우
우측 끝에 ) 몇개 있나
그 템포를 따라가야 한다면 유일
(?)?
? 왼쪽과 오른쪽의 갯수 차이가 정확히 ?개 만큼인가
특이 예시 )), ??
*/