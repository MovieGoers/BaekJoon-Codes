// 코드 미완성!

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
	static int N;
	static int[][] blocks;
	
	public static void main(String[] args) throws Exception{
		InitializeValues();
		GetInputs();
		SolveProblem();
		PrintAnswer();
	}
	
	public static void InitializeValues() {
		N = 0;
	}
	
	public static void GetInputs() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		blocks = new int[N][3];
		
		for(int i=0;i<N;i++) {
			String inputs[] = br.readLine().split(" ");
			for(int j=0;j<3;j++) {
				blocks[i][j] = inputs[j].charAt(0) - '0';
			}
		}
	}

	public static void SolveProblem() {
		for(int i=0;i<N;i++) {
			// 1. 각 blue, green 영역에 블록 넣기.
			// 2. blue의 열, green 의 행이 가득 찬 경우 제거하고 점수 얻기.
			// 3. 중력에 의해 블록들 다 내려가기.
			// 4. 넘치는 블록 내리기.
		}
	}
	
	public static void PrintAnswer() {
		
	}
	
	public static int GetNextPlace(int curr, int dice) {
		return curr + dice * 2;
	}
}
