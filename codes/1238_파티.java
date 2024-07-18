import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class Main{
	// N : 1 이상 1000 이하 , M : 1이상 10000이하.
	// 1번~N번 마을 또는 학생. M 개의 도로.
	// X번 마을 파티.
	static int INF = 987654321;
	static int N, M, X;
	
	// next[i]의 num, dist. i번 노드와 이어진 num 번 노드. 그 거리는 dist.
	static List<List<Node>> next;
	static List<List<Node>> reverseNext;
	
	static int answer = 0;

	static class Node implements Comparable<Node>{
		int num;
		int dist;

		public Node(int num, int dist) {
			this.num = num;
			this.dist = dist;
		}

		public int compareTo(Node n) {
			return this.dist - n.dist;
		}
	}
	
	public static void main(String[] args) throws Exception{
		GetInputs();
		SolveProblem();
		PrintAnswer();
	}
	
	static void GetInputs() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] str1 = br.readLine().split(" ");
		
		N = Integer.parseInt(str1[0]);
		M = Integer.parseInt(str1[1]);
		X = Integer.parseInt(str1[2]);

		next = new ArrayList<>();
		reverseNext = new ArrayList<>();
		for(int i=0;i<=N;i++) {
			next.add(new ArrayList<>());
			reverseNext.add(new ArrayList<>());
		}

		for(int i=0;i<M;i++) {
			String[] str2 = br.readLine().split(" ");
			int st = Integer.parseInt(str2[0]);
			int end = Integer.parseInt(str2[1]);
			int t = Integer.parseInt(str2[2]);
			
			next.get(st).add(new Node(end, t));
			reverseNext.get(end).add(new Node(st, t));
		}
	}

	static void SolveProblem() {
		int[] totalDist = new int[N+1];
		int[] dist1 = DoDijkstra(next, X); // 각 노드에서 X로 갈 때의 거리값.
		int[] dist2 = DoDijkstra(reverseNext, X); // X에서 각 노드로 갈 때의 거리값.
		
		for(int i=1;i<=N;i++) {
			totalDist[i] = dist1[i] + dist2[i];
		}
		
		int max = -1;
		for(int i=1;i<=N;i++) {
			if(i == X)
				continue;
			max = (max < totalDist[i])? totalDist[i] : max;
		}
		
		answer = max;
	}
	
	// start에서 각 노드까지의 최소 거리를 저장하는 배열 반환.
	static int[] DoDijkstra(List<List<Node>> list, int start) {
		boolean[] visited = new boolean[N+1];
		int[] dist = new int[N+1];
		
		Arrays.fill(dist, INF);
		
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(start, 0));
		
		dist[start] = 0;
		
		while(!pq.isEmpty()) {
			int curr = pq.poll().num;
			
			if(visited[curr])
				continue;
			
			visited[curr] = true;
			
			// 현재 노드 curr에서 이어진 노드들에 대해서,
			for(Node nextNode : list.get(curr)) {
				// 이전 거리보다 curr->nextNode로 가는 길이 더 빠른 경우 업데이트.
				if(dist[nextNode.num] > dist[curr] + nextNode.dist) {
					dist[nextNode.num] = dist[curr] + nextNode.dist;
					pq.add(new Node(nextNode.num, dist[nextNode.num]));
				}
			}
		}
		
		return dist;
	}
	
	static void PrintAnswer() {
		System.out.println(answer);
	}
	
	static void PrintDist(int[] dist) {
		for(int i=1;i<=N;i++) {
			System.out.printf("%d, ", dist[i]);
		}
		System.out.println();
	}
}
