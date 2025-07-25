import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());

        while(--T >= 0){
            int N = Integer.parseInt(br.readLine().trim());
            ArrayList<int[]> list = new ArrayList<>();
            for(int n=0;n<N;n++){
                int a, b;

                st = new StringTokenizer(br.readLine().trim());

                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());

                list.add(new int[] {a, b});
            }

            Collections.sort(list, new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    return o1[0] - o2[0];
                }
            });

            int best_rank = list.get(0)[1];
            int cnt = 1;

            for(int n=1;n<N;n++){
                if(list.get(n)[1] < best_rank){
                    best_rank = list.get(n)[1];;
                    cnt++;
                }
            }

            sb.append(cnt).append('\n');
        }

        System.out.print(sb);
    }
}