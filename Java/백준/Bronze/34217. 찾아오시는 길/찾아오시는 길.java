import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        int a, b;
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine().trim());
        int c, d;

        c = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());

        int e = a+c;
        int f = b+d;

        if(e < f){
            System.out.print("Hanyang Univ.");
        }else if(e > f) {
            System.out.print("Yongdap");
        }else {
            System.out.print("Either");
        }
    }
}