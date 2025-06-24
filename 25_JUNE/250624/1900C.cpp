#include <bits/stdc++.h>
#define ll long long
#define INF ((int)1e9 + 10)
#define lINF ((ll)1e18 + 10LL)
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> tree(2 * (n + 1), 0);
    vector<int> leafs;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        tree[i * 2] = l;
        tree[i * 2 + 1] = r;
        if (l == 0 && r == 0) {
            leafs.push_back(i);
        }
    }
    queue<int> bfsQ;
    bfsQ.push(1);
    vector<int> check(n + 1, -1);
    check[1] = 0;
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        int left = tree[now * 2];
        int right = tree[now * 2 + 1];
        if (left != 0) {
            if (check[left] == -1) {
                check[left] = check[now] + (str[now - 1] == 'L' ? 0 : 1);
                bfsQ.push(left);
            }
        }
        if (right != 0) {
            if (check[right] == -1) {
                check[right] = check[now] + (str[now - 1] == 'R' ? 0 : 1);
                bfsQ.push(right);
            }
        }
    }
    int ans = INF;
    for (auto &&i : leafs) {
        ans = min(ans, check[i]);
    }
    cout << ans << '\n';
}
// 리프를 찍턴이든 뭐든 할 수 있으려면, 몇번 바꿔야 하는가?
// 정점에 이미 어디로 가야하는지가 적혀있다.
/*
n < 30만
dfs?
무한루프를 막으며 리프 도착 여부 탐색 방법?
모든 리프에서 동시에 시작해서, 루트가 도달 가능한지
이미 방문한 곳이면, 그 자체로 무한루프?
두개 수정하면?
위에서 수정하지 그랬어
 */

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
1. int 오버플로우, out of bounds
2. 특수한 경우(n=1?)
3. 잘못된 가정 & 증명

*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기 & 구하고자 하는 것의 계층 구조 표현 -> 정확히 & 입체적으로 파악
*한가지 접근 방식에 얽메이지 말기 -> 응용의 끝 알기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기 -> 수식 & 그림화, 조건 정리
// 수행 목표
// 1. 아이디어 획득 : "추론"
//     - 문제 알고리즘/특징의 "증명"으로 아이디어
//         - {BruteForce, greedy, D&C, DP, graph, math}
//     - 전체 알고리즘이 “결국 구하고자 하는 것” 놓치지 않기
//     - “책임” 뽑아내기 -> 개념화, 정의, 추상화, 귀납적 사고
//         - 각 기능들이 어떤 책임을 가지고 있는지
//         - “어떤 패턴”으로 동작하는지
//     - 가장 Naive한 상태/알고리즘부터 시작하기 (완전 탐색, 단순 자료구조)
//     - 뚜렷한 증명이 나오지 않을 땐, 어떤 기준을 만들고 나눠서 보기
//     - 뚜렷한 최적화 기법이 떠오르지 않을 땐, 문제에 주어진 특이한 특징을 잡기
//     - 단위 동작의 조건 분기 파악
//     - 가장 극단적인 경우에서 추론 (가장 차이가 뚜렷한 예제)
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화, 엄밀한 조건 정리)
//     - 알고리즘 내에 어떤 역할들이 있는지 -> 직접 들어가보기
//     - 알고리즘 내에 어떤 기능들이 있는지 -> 직접 수행해보기
//     - "끝까지 구체화"로 접근해야, "깔끔한 추상화"가 나온다.
// 3. cutting | 구현(차근차근 단순화 & 최적화)

/*
수학적 접근 방법
1. 불변성
2. 극단성
3. 홀짝성
4. 단조성
5. 선형성
6. 영역성
*/

/*
정당성 증명 방법
1. 귀납법 -> 결과값 만드는 점화식의 존재성을 증명하는 것
2. 귀류법 -> 결과값의 참/거짓을 가정하고 이전단계의 모순을 발견하여 증명
3. 경우에 의한 증명 -> 반례 찾기
4. 구성적 증명 -> 부분문제의 결과값을 만드는 원인를 분석하여 증명하는 방법
5. 비둘기집의 원리
6. 대각선 논법(연역법) -> A<C 이고 C<B 임을 이용해 A<B를 증명하는 방법
*/

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 틀리면 느낌표 추가하기