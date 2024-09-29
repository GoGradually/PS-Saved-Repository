import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

//Change Class Name to Problem Name
public class B1_1995 {
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
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);
        int n = Integer.parseInt(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        Map<Long, Long> mp = new HashMap<>();
        line = br.readLine();
        st = new StringTokenizer(line);
        List<Long> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(Long.valueOf(st.nextToken()));
        }
        Collections.sort(arr);
        Long ans = 0L;
        for (int i = 0; i < n; i++) {
            Long now = arr.get(i);
            if(mp.get(now) == null){
                mp.put(now, 0L);
            }
            mp.put(now, mp.get(now) + 1);
            
            // 현재까지 구매 계산

            // 가격 오버되면, 정상 될때까지 저렴한 가격 제거
            // 이거 반복문 시간초과 삘인데
            // 이분탐색으로 구현?
            // 그리디한 최적 가격이 있나?
            // 재수없게 1 더 커서 이전 가격보다 지금 가격 빼는게 나은경우
            // 그런 경우는 이전에 해결됐겠지
            // 더이상 이전 가격은 추가되지 않는다

            Long remain = m;
            if(mp.get(now) != null){
                remain -= now * mp.get(now);
            }
            if(remain>= 0){
                ans = Math.max(ans, m - remain);
                if(mp.get(now-1) != null){
                    Long can = mp.get(now-1);
                    Long should = remain / (now - 1);
                    ans = Math.max(ans, m - (remain - Math.min(can * (now - 1), should * (now - 1))));
                }
                
            }
        }
        bw.write(String.valueOf(ans) + '\n');
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