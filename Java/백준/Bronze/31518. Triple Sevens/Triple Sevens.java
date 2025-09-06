import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine().trim());

        int cnt = 0;
        for(int i=0;i<3;i++){
            st = new StringTokenizer(br.readLine().trim());

            for(int j=0;j<N;j++){
                int val = Integer.parseInt(st.nextToken());

                if(val == 7){
                    cnt++;
                    break;
                }
            }
        }

        if(cnt == 3) {
            System.out.print(777);
        }else {
            System.out.print(0);
        }
    }
}