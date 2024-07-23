import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main{
	static int N, K; // 0 <= N <= 100000, 0 <= K <= 100000
	static int[] dt = {0, 1, 1};
	
	static class Info implements Comparable<Info>{
		int pos;
		int time;
		
		public Info(int pos, int time) {
			this.pos = pos;
			this.time = time;
		}

		@Override
		public int compareTo(Info o) {
			return (this.time - o.time);
		}
	}
	
	public static void main(String[] args) throws Exception{
		HandleInput();
		SolveProblem();
	}
	
	static void HandleInput() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inputs[] = br.readLine().split(" ");
		
		N = Integer.parseInt(inputs[0]);
		K = Integer.parseInt(inputs[1]);
	}
	
	static void SolveProblem() {
		DoDijkstra();
	}
	
	static void DoDijkstra() {
		int[] dist = new int[100001];
		
		Arrays.fill(dist, 1987654321);
		
		PriorityQueue<Info> q = new PriorityQueue<>();
		
		q.add(new Info(N, 0));
		dist[N] = 0;
		
		while(!q.isEmpty()) {
			Info cur = q.poll();

			// 이미 구한 값보다 커진 경우 가지 치기.
			if(cur.time > dist[K])
				continue;
			
			int[] nextPos = {cur.pos * 2, cur.pos+1, cur.pos-1};

			for(int i=0;i<3;i++) {
				// 범위 밖
				if(nextPos[i] < 0 || nextPos[i] > 100000)
					continue;
				
				// 이전 값보다 현재 노드를 거쳐 가는 게 더 빠른 경우.
				if(dist[nextPos[i]] > dist[cur.pos] + dt[i]) {
					dist[nextPos[i]] = dist[cur.pos] + dt[i];
					
					q.add(new Info(nextPos[i], dist[nextPos[i]]));
				}
			}
		}
		
		System.out.println(dist[K]);
	}
}
