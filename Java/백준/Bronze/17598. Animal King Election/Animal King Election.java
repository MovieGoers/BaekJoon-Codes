import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cnt = 0;

        for(int i=0;i<9;i++){
            if(br.readLine().trim().charAt(0) == 'T')
                cnt++;
        }

        if(cnt > 4) {
            System.out.print("Tiger");
        }else {
            System.out.print("Lion");
        }
    }
}