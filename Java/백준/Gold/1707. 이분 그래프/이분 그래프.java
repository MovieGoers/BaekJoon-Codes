import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static List<Integer>[] graph;
    static int[] color;
    static StringBuilder sb = new StringBuilder();
    static boolean isBipartite;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;


        int K = Integer.parseInt(br.readLine().trim());

        while(--K >= 0){
            st = new StringTokenizer(br.readLine().trim());

            int V, E;
            V = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());

            graph = new ArrayList[V+1];

            for(int v=1;v<=V;v++){
                graph[v] = new ArrayList<>();
            }

            color = new int[V+1];

            for(int e=0;e<E;e++){
                st = new StringTokenizer(br.readLine().trim());

                int u, v;

                u = Integer.parseInt(st.nextToken());
                v = Integer.parseInt(st.nextToken());

                graph[u].add(v);
                graph[v].add(u);
            }

            isBipartite = true;

            for(int v=1;v<=V;v++){
                if(!isBipartite)
                    break;

                if(color[v] == 0){
                    colorBFS(v);
                }
            }

            sb.append((isBipartite) ? "YES\n" : "NO\n");
        }

        System.out.print(sb);
    }

    static void colorBFS(int start){
        Queue<int[]> q = new LinkedList<>();
        color[start] = 1;
        q.offer(new int[] {start, 1}); // 앞 숫자는 정점 번호, 뒤 숫자는 칠해진 색.

        while(!q.isEmpty()){
            int[] current = q.poll();

            for(int next : graph[current[0]]){
                if(color[next] == 0){
                    color[next] = current[1] * -1;
                    q.offer(new int[] {next, color[next]});
                }else if(color[next] == current[1]){
                    isBipartite = false;
                    return;
                }
            }
        }
    }
}