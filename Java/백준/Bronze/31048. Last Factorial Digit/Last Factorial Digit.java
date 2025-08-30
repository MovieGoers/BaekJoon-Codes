import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine().trim());

        while(--T >= 0){
            int N = Integer.parseInt(br.readLine().trim());

            int value = 1;
            for(int i=1;i<=N;i++){
                value *= i;
                value %= 10;
            }

            sb.append(value).append('\n');
        }

        System.out.print(sb);
    }
}