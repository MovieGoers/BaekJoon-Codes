import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int[][] costs = {{30, 40}, {35, 30}, {40, 20}};

        while(true) {
            String[] strs = br.readLine().trim().split(" ");

            int call, data;
            call = Integer.parseInt(strs[0]);
            data = Integer.parseInt(strs[1]);

            if(call == 0 && data == 0){
                break;
            }

            int minCost = 1987654321;
            for(int i=0;i<3;i++){
                int cost = call * costs[i][0] + data * costs[i][1];

                minCost = Integer.min(cost, minCost);
            }

            sb.append(minCost).append('\n');
        }

        System.out.println(sb);
    }
}