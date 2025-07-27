import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        int N, M;

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int[][] costMap = new int [N+1][N+1];
        int[][] destinations = new int[N+1][N+1];

        for(int n=1;n<=N;n++){
            Arrays.fill(costMap[n], Integer.MAX_VALUE / 2);
            costMap[n][n] = 0;
            for(int j=1;j<=N;j++){
                destinations[n][j] = j;
            }
        }

        for(int m=0;m<M;m++){
            st = new StringTokenizer(br.readLine().trim());

            int from, to, cost;

            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(st.nextToken());

            costMap[from][to] = cost;
            costMap[to][from] = cost;
        }
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    if(costMap[i][j] > costMap[i][k] + costMap[k][j]) {
                        costMap[i][j] = costMap[i][k] + costMap[k][j];
                        destinations[i][j] = destinations[i][k];
                    }
                }
            }
        }

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i == j){
                    sb.append("- ");
                }else{
                    sb.append(destinations[i][j]).append(' ');
                }
            }
            sb.append('\n');
        }

        System.out.print(sb);
    }
}