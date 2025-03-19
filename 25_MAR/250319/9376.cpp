#include <bits/stdc++.h>
#define ll long long
#define INF ((int)1e9 + 10)
#define lINF ((ll)1e18 + 10LL)
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

// *:2
// #:1
// .:0 -> $:0

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<vector<int>> bfs(pair<int, int> start, vector<vector<int>>& arr) {
    deque<pair<int, int>> bfsQ;
    bfsQ.push_back(start);
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> check(n, vector<int>(m, -1));
    check[start.first][start.second] = 0;

    while (!bfsQ.empty()) {
        int x, y;
        tie(x, y) = bfsQ.front();
        bfsQ.pop_front();
        for (int k = 0; k < 4; k++) {
            int p = x + dx[k], q = y + dy[k];
            if (p < 0 || p >= n || q < 0 || q >= m) continue;
            if (arr[p][q] == 2) continue;
            if (check[p][q] == -1) {
                if (arr[p][q] == 1) {
                    check[p][q] = check[x][y] + 1;
                    bfsQ.push_back({p, q});
                } else if (arr[p][q] == 0) {
                    check[p][q] = check[x][y];
                    bfsQ.push_front({p, q});
                }
            }
        }
    }

    return check;
}

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 2, vector<int>(m + 2, 0));
    vector<pair<int, int>> point;
    point.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            if (str[j - 1] == '*') {
                arr[i][j] = 2;
            } else if (str[j - 1] == '#') {
                arr[i][j] = 1;
            } else if (str[j - 1] == '$') {
                point.push_back({i, j});
            }
        }
    }
    int ans = INF;
    vector<vector<int>> check1 = bfs(point[0], arr);
    vector<vector<int>> check2 = bfs(point[1], arr);
    vector<vector<int>> check3 = bfs(point[2], arr);
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            if (check1[i][j] == -1 || check2[i][j] == -1 || check3[i][j] == -1)
                continue;
            int now = check1[i][j] + check2[i][j] + check3[i][j];
            if (arr[i][j] == 1) now -= 2;
            ans = min(ans, now);
        }
    }

    cout << ans << '\n';
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