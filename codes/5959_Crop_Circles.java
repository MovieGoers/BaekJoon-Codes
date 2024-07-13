import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Arrays;

public class Main {

	static int N;
	static int[][] circles;
	static int[] answers;
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(br.readLine());
		
		circles = new int[N][3];
		answers = new int[N];
		Arrays.fill(answers, 0);
		
		for(int i=0;i<N;i++) {
			String[] str = br.readLine().split(" ");
			for(int j=0;j<3;j++) {
				circles[i][j] = Integer.parseInt(str[j]);
			}
		}
		
		for(int i=0;i<N-1;i++) {
			for(int j=i+1;j<N;j++) {
				if(CheckIfInner(i, j)) {
					++answers[i];
					++answers[j];
				}
			}
		}
		
		for(int i=0;i<N;i++) {
			sb.append(answers[i]).append('\n');
		}
		
		System.out.println(sb);
	}
	
	public static Boolean CheckIfInner(int a, int b) {
		Boolean flag = false;
		
		if(Math.pow(circles[a][2] + circles[b][2], 2) > Math.pow(circles[a][0] - circles[b][0], 2) + Math.pow(circles[a][1] - circles[b][1], 2))
			flag = true;
		
		return flag;
	}

}
