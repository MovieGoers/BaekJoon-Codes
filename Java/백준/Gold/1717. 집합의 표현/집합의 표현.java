import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] parents;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        parents = new int[n+1];

        for(int i=0;i<=n;i++){
            parents[i] = i;
        }

        while(--m >= 0){
            st = new StringTokenizer(br.readLine().trim());

            int command = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(command == 0){
                union(a, b);
            }else{
                if(find(a) == find(b)){
                    sb.append("YES\n");
                }else{
                    sb.append("NO\n");
                }
            }
        }

        System.out.print(sb);

    }

    static int find(int x){
        if(x == parents[x])
            return x;

        return parents[x] = (find(parents[x]));
    }

    static boolean union(int x, int y){
        int parentX = find(x);
        int parentY = find(y);

        if(parentX == parentY)
            return false;

        parents[parentY] = parentX;

        return true;
    }
}