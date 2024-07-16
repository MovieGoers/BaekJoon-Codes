import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
	static int T;
	static int[][] arr;
	static int[][] inputs;
	static StringBuilder answerSB = new StringBuilder();

	public static void main(String[] args) throws Exception{
		InitializeValues();
		GetInputs();
		SolveProblem();
		PrintAnswer();
	}
	
	public static void InitializeValues() {
		T = 0;
		arr = new int[31][31];
	}
	
	public static void GetInputs() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		
		inputs = new int[T][2];
		
		for(int i=0;i<T;i++) {
			String inputStr[] = br.readLine().split(" ");
			inputs[i][0] = Integer.parseInt(inputStr[0]);
			inputs[i][1] = Integer.parseInt(inputStr[1]);
		}
	}

	public static void SolveProblem() {
		for(int i=1;i<=30;i++) {
			arr[1][i] = i;
		}
		
		for(int i=2;i<=30;i++) {
			for(int j=i;j<=30;j++) {
				arr[i][j] = arr[i-1][j-1] + arr[i][j-1];
			}
		}
		
		for(int i=0;i<T;i++) {
			answerSB.append(arr[inputs[i][0]][inputs[i][1]]).append('\n');
		}
	}
	
	public static void PrintAnswer() {
		System.out.println(answerSB);
	}
}
