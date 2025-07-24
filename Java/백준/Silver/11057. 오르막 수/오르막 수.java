import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        int[][] dp = new int[N][11];

        Arrays.fill(dp[0], 1);

        for(int endNum = 1; endNum <= 10; endNum++){
            for(int digit = 1; digit < N; digit++){
                dp[digit][endNum] = (dp[digit - 1][endNum] + dp[digit][endNum - 1]) % 10007;
            }
        }


        int sum = 0;

        for(int i=1;i<=10;i++) {
            sum += dp[N-1][i];
        }

        System.out.print(sum % 10007);
    }
}