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
    ll n;
    cin >> str >> n;
    stack<int> stk;
    vector<int> order;
    for (int i = 0; i < str.size(); i++) {
        while (!stk.empty() && str[stk.top()] > str[i]) {
            order.push_back(stk.top());
            stk.pop();
        }
        stk.push(i);
    }

    while (!stk.empty()) {
        order.push_back(stk.top());
        stk.pop();
    }

    vector<int> on(str.size(), 1);
    ll length = str.size();
    int cnt = 0;
    while (n > length) {
        n -= length;
        length--;
        on[order[cnt]] = 0;
        cnt++;
    }
    for (int i = 0; i < str.size(); i++) {
        n -= on[i];
        if (n == 0) {
            cout << str[i];
            break;
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
abcef
가장 뒷 문자를 제거한다?
그러면 무조건 앞에오긴 하는데
그게 항상 최소인가?
bacdef
bacde
acdef
"앞에서부터 처음 꺾이는 걸 제거" -> 항상 뒤에 더 짧은애가 온다.
근데 이게 최소인가? 일단 처음 꺾이기 전걸 제거하면 무조건 더 늦는다
그럼 처음 꺾이고 난 뒤 걸 제거하면 -> 무조건 앞자리에서 더 늦는다
sdgnwln
dgnwln
문자열을 그래프로 그리면
1. 일단 앞에서부터 비내림차순 만들고
2. 뒤에서부터 하나씩 제거하기
-> 스택과 큐를 이용해서 하나씩 제거할 순서를 만들어두고
-> 그걸 이용해서 pos를 추측한다?
*/

// commit 시 피드백할 것 Message로 남겨두기!!