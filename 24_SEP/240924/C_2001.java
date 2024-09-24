import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

//Change Class Name to Problem Name
public class C_2001 {
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
        Dsu dsu = new Dsu(n);
        StringBuilder sBuilder = new StringBuilder();
        sBuilder.append("! ");
        while(true){
            int next = -1;
            int now = 0;
            for (int i = 1; i < n; i++) {
                if(dsu.find(i) != dsu.find(now)){
                    next = i;
                    break;
                }
            }
            if(next == -1){
                break;
            }
            while(true){
                int x = query(br, bw, now, next);
                if(x == now){
                    dsu.merge(x, next);
                    sBuilder.append(String.valueOf(x + 1)).append(" ").append(String.valueOf(next + 1)).append(" ");
                    break;
                }
                if(dsu.find(x) == dsu.find(now)){
                    now = x;
                }
                else if(dsu.find(x) == dsu.find(next)){
                    next = x;
                }
                else if(dsu.find(x) != dsu.find(next) && dsu.find(x) != dsu.find(now)){
                    next = x;
                }
            }
        }
        bw.write(sBuilder.toString() + '\n');
        bw.flush();
    }

    static class Dsu{
        public int[] parent, rank;
        public Dsu(int n){
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        public int find(int now){
            if(parent[now] == now){
                return now;
            }
            return parent[now] = find(parent[now]);
        }

        public void merge(int u, int v){
            u = find(u);
            v = find(v);
            if(rank[u] < rank[v]){
                int temp = u;
                u = v;
                v = temp;
            }
            parent[v] = u;
            if(rank[u] == rank[v]) rank[u]++;
        }
    }

    private static int query(BufferedReader br, BufferedWriter bw, int a, int b) throws NumberFormatException, IOException{
        String strA = String.valueOf(a + 1);
        String strB = String.valueOf(b + 1);
        bw.write("? " + strA + " " + strB + '\n');
        bw.flush();
        int x = Integer.parseInt(br.readLine());
        return x - 1;
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