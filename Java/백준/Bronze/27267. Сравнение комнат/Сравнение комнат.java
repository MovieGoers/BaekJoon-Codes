import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        int M = 1, P = 1;

        for(int i=0;i<2;i++){
            int value = Integer.parseInt(st.nextToken());
            M *= value;
        }

        for(int i=0;i<2;i++){
            int value = Integer.parseInt(st.nextToken());
            P *= value;
        }

        if(M > P)
            System.out.print('M');
        else if(M < P)
            System.out.print('P');
        else
            System.out.print('E');
    }
}