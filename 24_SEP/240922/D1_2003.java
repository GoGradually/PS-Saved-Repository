import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

//Change Class Name to Problem Name
public class D1_2003 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int test = Integer.parseInt(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < test; i++) {
            solve(br, bw);
        }
        bw.flush();
    }

    public static void solve(BufferedReader br, BufferedWriter bw) throws IOException{
        String nm = br.readLine();
        StringTokenizer tokenNM = new StringTokenizer(nm);
        int n = Integer.parseInt(tokenNM.nextToken());
        long m = Long.parseLong(tokenNM.nextToken());
        long max = 0L;
        for (int i = 0; i < n; i++) {     
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line);
            int count = Integer.parseInt(st.nextToken());
            long[] arr = new long[count + 3];
            for (int j = 0; j < count; j++) {
                int now = Integer.parseInt(st.nextToken());
                if(now <= count + 2) arr[now] = 1;
            }
            int flag = 0;
            while(arr[flag] != 0) flag++;
            arr[flag] = 1;
            while(arr[flag] != 0) flag++;
            max = Math.max(flag, max);
        }
        long ans = m*(m+1) / 2;
        long point = Math.min(max, m);
        ans -= point*(point+1)/2;
        ans += max*(point + 1);
        System.out.println(ans);
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
//         - {BruteForce, greedy, D&C, DP, graph, math}-
//     - “책임” 뽑아내기
//         - 각 기능들이 어떤 책임을 가지고 있는지
//         - “어떤 패턴”으로 동작하는지
//     - 가장 Naive한 상태/알고리즘부터 시작하기 (완전 탐색, 단순 자료구조)
//     - 단위 동작의 조건 분기 파악
//     - 가장 극단적인 경우에서 추론 (가장 차이가 뚜렷한 예제)
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화, 엄밀한 조건 정리)
//     - 알고리즘 내에 어떤 역할들이 있는지 -> 직접 들어가보기
//     - 알고리즘 내에 어떤 기능들이 있는지 -> 직접 수행해보기
// 3. cutting | 구현(차근차근 단순화 & 최적화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 틀리면 느낌표 추가하기