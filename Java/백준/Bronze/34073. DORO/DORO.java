import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(br.readLine().trim());

        String[] strs = br.readLine().trim().split(" ");

        for(int i=0;i<N;i++){
            sb.append(strs[i]).append("DORO").append(' ');
        }

        System.out.print(sb);
    }
}