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
            String str = br.readLine().trim();

            int N = str.length();
            int cnt = 0;
            for(int n=0;n<N;n++){
                if(str.charAt(n) == 'a')
                    cnt++;
            }

            sb.append(Integer.min(N - cnt, cnt)).append('\n');
        }
        
        System.out.print(sb);
    }
}