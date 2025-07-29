import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine().trim());

        ArrayList<int[]> list = new ArrayList<>();

        for(int n=0;n<N;n++){
            list.add(new int[] {Integer.parseInt(st.nextToken()), n});
        }

        Collections.sort(list, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        int[] p = new int[N];

        for(int n=0;n<N;n++){
            p[list.get(n)[1]] = n;
        }

        for(int n=0;n<N;n++){
            sb.append(p[n]).append(' ');
        }

        System.out.print(sb);
    }
}