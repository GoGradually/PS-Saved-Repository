import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

//Change Class Name to Problem Name
public class C_1995 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < test; i++) {
            run(br, bw);
        }
        bw.flush();
    }

    public static void run(BufferedReader br, BufferedWriter bw) throws IOException{
        int n = Integer.parseInt(br.readLine());
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);
        
    }
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
//     - “책임” 뽑아내기
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
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

오버플로우를 막는 비교 방법
2^몇승까지 가지고 있는지
결국 제곱이라는 건 소수의 제곱
소수의 갯수가 7만개네
그럼 안되는데
모든 수를 자릿수와 그 값으로표현하면 좀 편한가? 그래도 2^200000
    테트레이션에서 그나마 나아진 것
추정이 정답을 만들 수는 없나?
a가 x번 했군, 그럼 나는 y번 하면 되겠군

1. 계산할 수 있는 영역 안에 가두기
2. 나 말고 상대방이 제곱한다 = 내가 제곱 한번 덜한다
3. 내가 제곱한 횟수 - 상대방이 제곱한 횟수 = 진짜 나의 제곱한 횟수
4. 근데 이러면 내가 제곱 두번해서 오버플로우나면?
5. 10^6 이기때문에, 10^10승 을 제곱할 일이 안나온다?
    5-1. 내 크기는 최대 10^6
    5-2. 상대방의 크기는 따라서 최대 10^11승
    5-3. 근데 그러면 제곱하는 순간 10^12승 끝
    5-4. 한번 제곱에 크기가 안뒤집히는 경우가 있을까?
투어리스트는 어떻게 해결했나
    연산을 덜함

정수로 로그를 다루는 방법에 대한 문제
로그의 아이디어를 문제에 차용...?
왜 이전 제곱한걸 그대로 더해줄 수 있는거지?
역전 현상이 왜 안일어나는거지????
어떻게 저게 되는거지??????????????
a^x^2 < b^y^2 인데
a^x >= b^y 인 경우는 없다
이건 밑 전체를 제곱하는 경우라, 무조건 불변성이 성립한다.

a^x < b^y 인데
a^(x+1) > b^(y+1) 인 경우는... a가 크면 가능하다

1 초과인 a, b, x, y에 대하여
a^x < b^y 이고
a^x^2 > b^y 이면
a^x^2 < b^y^2 이다
a^x = p, b^y = q 라고 하면
p < q 이다
p * p < q * p 이므로
p * p < q * q 는 당연히 성립한다.
*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 틀리면 느낌표 추가하기