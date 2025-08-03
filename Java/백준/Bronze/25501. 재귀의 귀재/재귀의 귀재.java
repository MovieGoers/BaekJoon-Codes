import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int recursionCnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());

        while(--T >= 0){
            String input = br.readLine().trim();

            recursionCnt = 0;

            sb.append(isPalindrome(input));
            sb.append(' ').append(recursionCnt).append('\n');
        }

        System.out.print(sb);
    }

    public static int recursion(String s, int l, int r){
        ++recursionCnt;
        if(l >= r) return 1;
        else if(s.charAt(l) != s.charAt(r)) return 0;
        else return recursion(s, l+1, r-1);
    }

    public static int isPalindrome(String s){
        return recursion(s, 0, s.length()-1);
    }
}