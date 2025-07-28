import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());

        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        int[] arr = new int[N];

        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int X = Integer.parseInt(br.readLine().trim());

        int left = 0;
        int right = N-1;
        int cnt = 0;

        while(left<right){
            int sum = arr[left] + arr[right];
            if(sum > X){
                --right;
            }else if(sum < X){
                ++left;
            }else{
                ++cnt;
                ++left;
            }
        }

        System.out.println(cnt);
    }
}