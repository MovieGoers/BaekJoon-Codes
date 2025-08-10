import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        int min = 1987654321;
        int n, C;
        n = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        while(--n >= 0){
            st = new StringTokenizer(br.readLine().trim());

            int a, b, c;
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            int value = a + b + c * C;

            if(value < min){
                min = value;
            }
        }

        System.out.print(min);
    }
}