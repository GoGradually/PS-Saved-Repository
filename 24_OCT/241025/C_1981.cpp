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
    vector<ll> arr(n);
    vector<pair<ll, int>> b;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == -1) {
            if (!b.empty() && b.back().first == -1) {
                b.back().second++;
            } else {
                b.push_back({-1, 1});
            }
        } else {
            b.push_back({arr[i], 1});
        }
        ans[i] = arr[i];
    }
    if (b.size() == 1) {
        if (b[0].first == -1) {
            int d = 2;
            for (int i = 0; i < n; i++) {
                cout << d << ' ';
                d = 3 - d;
            }
            cout << '\n';
        } else {
            cout << b[0].first << '\n';
        }
        return;
    }

    if (b[0].first == -1) {
        int d = b[1].first * 2;
        int cc = 3 * d;
        for (int i = b[0].second - 1; i >= 0; i--) {
            ans[i] = d;
            d = cc - d;
        }
    }
    if (b.back().first == -1) {
        int d = b[b.size() - 2].first * 2;
        int cc = 3 * d;
        for (int i = n - b.back().second; i < n; i++) {
            ans[i] = d;
            d = cc - d;
        }
    }

    int index = b[0].second;
    for (int now = 1; now < b.size() - 1; now++) {
        if (b[now].first == -1) {
            ll left = b[now - 1].first;
            ll right = b[now + 1].first;
            bool ok = false;
            for (ll i = left, lCnt = 0; i > 0; i >>= 1, lCnt++) {
                for (ll j = right, rCnt = 0; j > 0; j >>= 1, rCnt++) {
                    if (i == j) {
                        ll x = lCnt + rCnt - 1;
                        if (x > b[now].second) {
                            continue;
                        }
                        if ((b[now].second - x) % 2 != 0) {
                            continue;
                        }
                        if (b[now].second > x) {
                            for (int tt = index; tt < index + b[now].second - x;
                                 tt += 2) {
                                // 4칸 중 2칸 제거 -> index + b[now].second(4) -
                                // x(2)
                                ans[tt] = ans[index - 1] * 2;
                                ans[tt + 1] = ans[index - 1];
                            }

                            index += b[now].second - x;
                            b[now].second = x;
                        }

                        for (int p = 0; p < lCnt; p++) {
                            ans[index + p] = left >> (p + 1);
                        }
                        for (int q = 0; q < rCnt; q++) {
                            ans[index + b[now].second - q] = right >> q;
                        }
                        ok = true;
                    }
                    if (ok) break;
                }
                if (ok) break;
            }

            if (!ok) {
                cout << -1 << '\n';
                return;
            }
        }
        index += b[now].second;
    }

    for (int i = 0; i < n - 1; i++) {
        if (ans[i] / 2 == ans[i + 1] || ans[i + 1] / 2 == ans[i]) continue;
        cout<<-1<<'\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
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
1. int 오버플로우, out of bounds
2. 특수한 경우(n=1?)
3. 잘못된 가정 & 증명

*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기 & 구하고자 하는 것의 계층 구조 표현 -> 정확히 & 입체적으로 파악
*한가지 접근 방식에 얽메이지 말기 -> 응용의 끝 알기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. 아이디어 획득 : "추론"
//     - 문제 알고리즘/특징의 "증명"으로 아이디어
//         - {BruteForce, greedy, D&C, DP, graph, math}
//     - 전체 알고리즘이 “결국 구하고자 하는 것” 놓치지 않기
//     - “책임” 뽑아내기 -> 개념화, 정의, 추상화
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