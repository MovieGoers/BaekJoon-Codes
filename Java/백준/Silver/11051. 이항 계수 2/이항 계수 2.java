import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N, K;

        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int[][] dp = new int[N+1][K+1];

        for(int n=0;n<=N;n++){
            for(int k=0;k<=K;k++){
                if(k == 0 || k == n)
                    dp[n][k] = 1;
                else if(k<n)
                    dp[n][k] = (dp[n-1][k-1] + dp[n-1][k]) % 10007;
            }
        }

        System.out.print(dp[N][K]);
    }
}