// NOT COMPLETE !!

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
	static List<List<Node>> next;
	static List<List<Node>> reverseNext;
	static int[] dist;
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
		
		dist = new int[N+1];
		Arrays.fill(dist, INF);
		
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
		DoDijkstra(next, X);
		DoDijkstra(reverseNext, X);
	}
	
	static void DoDijkstra(List<List<Node>> list, int start) {
		boolean[] visited = new boolean[N+1];
		PriorityQueue<Node> pq = new PriorityQueue<>();
		pq.add(new Node(start, 0));
		
		dist[start] = 0;
		
		while(!pq.isEmpty()) {
			int curr = pq.poll().num;
			
			if(visited[curr])
				continue;
			
			visited[curr] = true;
			
			for(Node nextNode : list.get(curr)) {
				if(dist[nextNode.num] > dist[curr] + nextNode.dist) {
					dist[nextNode.num] = dist[curr] + nextNode.dist;
					pq.add(new Node(nextNode.num, dist[nextNode.num]));
				}
			}
		}
	}
	
	static void PrintAnswer() {
		
	}
}
