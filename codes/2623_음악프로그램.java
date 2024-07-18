import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.ArrayList;

public class Main{
	static int N, M; // N : 1 이상 1000이하 , M : 1이상 100이하.
	static ArrayList<ArrayList<Integer>> graph;
	static int[] in = new int[1001];
	static StringBuilder sb = new StringBuilder();
	static boolean[] printed = new boolean[1001];
	static boolean isAnswerFound;
	
	public static void main(String[] args) throws Exception{
		InitializeValues();
		GetInputs();
		SolveProblem();
		PrintAnswer();
	}
	
	public static void InitializeValues() {
		N = 0;
		M = 0;
		isAnswerFound = true;
	}
	
	public static void GetInputs() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] str1 = br.readLine().split(" ");
		N = Integer.parseInt(str1[0]);
		M = Integer.parseInt(str1[1]);
		
		graph = new ArrayList<>();
		for(int i=0;i<=N;i++) {
			graph.add(new ArrayList<>());
		}
		
		for(int i=0;i<M;i++) {
			String[] str2 = br.readLine().split(" ");
			int size = Integer.parseInt(str2[0]);
			for(int j=2;j<=size;j++) {
				int prev = Integer.parseInt(str2[j-1]);
				int next = Integer.parseInt(str2[j]);
				graph.get(prev).add(next);
				++in[next];
			}
		}
	}

	public static void SolveProblem() {
		Queue<Integer> Q = new LinkedList<>();
		
		int cnt = 0;
		
		for(int i=1;i<=N;i++) {
			if(in[i] == 0)
				Q.add(i);
		}
		
		if(Q.isEmpty()) {
			isAnswerFound = false;
		}
		
		while(!Q.isEmpty()) {
			// 큐에서 pop
			int curr = Q.poll();
			printed[curr] = true;
			cnt++;
			
			sb.append(curr).append('\n');
			
			int size = graph.get(curr).size();
			
			for(int i=0;i<size;i++) {
				--in[graph.get(curr).get(i)];
				if(in[graph.get(curr).get(i)] == 0 && !printed[graph.get(curr).get(i)])
					Q.add(graph.get(curr).get(i));
			}
		}
		
		if(cnt != N) {
			isAnswerFound = false;
		}
	}
	
	public static void PrintAnswer() {
		if(isAnswerFound)
			System.out.println(sb);
		else
			System.out.println(0);
	}
}
