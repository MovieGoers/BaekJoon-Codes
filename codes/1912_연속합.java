import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
	static int N, answer;
	static int[] arr;

	public static void main(String[] args) throws Exception{
		InitializeValues();
		GetInputs();
		SolveProblem();
		PrintAnswer();
	}
	
	public static void InitializeValues() {
		N = 0;
		answer = -987654321;
	}
	
	public static void GetInputs() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		arr = new int[N];
		String[] strs = br.readLine().split(" ");

		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(strs[i]);
		}
	}

	public static void SolveProblem() {
		int sum = 0;
		for(int i=0;i<N;i++) {
			sum += arr[i];
			answer = (answer < sum)? sum : answer;
			if(sum < 0) {
				sum = 0;
			}
		}
	}
	
	public static void PrintAnswer() {
		System.out.println(answer);
	}
}
