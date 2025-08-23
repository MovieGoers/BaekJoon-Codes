import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());

        int N, M;

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int cnt = 0;

        for(int n=0;n<N;n++){
            String str = br.readLine().trim();

            for(int m=0;m<M;m++){
                if(str.charAt(m) == '+'){
                    cnt++;
                    break;
                }
            }
        }

        System.out.print(cnt);
    }
}