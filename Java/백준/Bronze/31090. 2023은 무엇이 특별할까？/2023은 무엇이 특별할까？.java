import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        while(--N >= 0){
            String input = br.readLine().trim();

            int year = Integer.parseInt(input) + 1;
            int divider = Integer.parseInt(input.substring(2, 4));

            if(year % divider == 0) {
                sb.append("Good\n");
            }else {
                sb.append("Bye\n");
            }
        }

        System.out.print(sb);
    }
}