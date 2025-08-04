import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine().trim();

        boolean[] isChecked = new boolean[26];
        char[] password = new char[26];

        int idx = 0;

        for(int i=0;i<str.length();i++){
            if(!isChecked[str.charAt(i) - 'A']){
                password[idx++] = str.charAt(i);
                isChecked[str.charAt(i) - 'A'] = true;
            }
        }

        int newIdx = 0;

        while(idx<26){
            if(!isChecked[newIdx]) {
                password[idx++] = (char) ('A' + newIdx);
            }
            newIdx++;
        }

        StringBuilder sb = new StringBuilder();

        String originalStr = br.readLine().trim();

        for(int i=0;i<originalStr.length();i++){
            sb.append(password[originalStr.charAt(i) - 'A']);
        }

        System.out.print(sb);
    }
}