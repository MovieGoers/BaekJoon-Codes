import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine().trim());

        for(int i=0;i<N*2;i++){
            for(int j=0;j<N;j++){
                if(j % 2 == 0){
                    if(i % 2 == 0)
                        sb.append('*');
                    else
                        sb.append(' ');
                }else{
                    if(i % 2 == 0)
                        sb.append(' ') ;
                    else
                        sb.append('*');
                }
            }
            sb.append('\n');
        }

        System.out.print(sb);
    }
}