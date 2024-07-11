import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception{
		new Main().solution();
	}

	private void solution() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int N, K, answer = Integer.MIN_VALUE;
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		int[] arr = new int[N];
		int[] sumArr = new int[N+1];
		
		sumArr[0] = 0;
		
		st = new StringTokenizer(br.readLine());
		
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			sumArr[i+1] = sumArr[i] + arr[i];
		}
		
		for(int i=0;i<N-K+1;i++) {
			int newValue = sumArr[i + K] - sumArr[i];
			answer = (answer < newValue) ? newValue : answer;
		}
		System.out.println(answer);
	}
}
