import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int total = 0;

        int N = Integer.parseInt(br.readLine().trim());

        for(int i=0;i<N;i++){
            if(i % 2 == 0)
                total += 3;
            else
                total -= 2;
        }

        System.out.print(total);
    }
}