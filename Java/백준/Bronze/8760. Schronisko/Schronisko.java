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
            String[] str = br.readLine().trim().split(" ");

            int mult = Integer.parseInt(str[0]) * Integer.parseInt(str[1]);

            sb.append(mult / 2).append('\n');
        }

        System.out.print(sb);
    }
}