import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
	static int N, M; // N : 1 이상 1000이하 , M : 1이상 100이하.
	static int[][] next = new int[1001][1001];
	
	public static void main(String[] args) throws Exception{
		InitializeValues();
		GetInputs();
		SolveProblem();
		PrintAnswer();
	}
	
	public static void InitializeValues() {
		N = 0;
		M = 0;
	}
	
	public static void GetInputs() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] str1 = br.readLine().split(" ");
		N = Integer.parseInt(str1[0]);
		M = Integer.parseInt(str1[1]);
		
		for(int i=0;i<M;i++) {
			String[] str2 = br.readLine().split(" ");
			int size = Integer.parseInt(str2[0]);
			for(int j=0;j<size;j++) {
				int k = Integer.parseInt(str2[j+1]);
			}
		}
		
	}

	public static void SolveProblem() {
		
	}
	
	public static void PrintAnswer() {

	}
}
