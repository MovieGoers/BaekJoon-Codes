import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String[] inputStr = br.readLine().split(" ");
		
		int N = Integer.parseInt(inputStr[0]);
		int M = Integer.parseInt(inputStr[1]);
		int min = 987654321;
		int answer = 0;
		
		for(int i=0;i<M;i++) {
			int a;
			String[] inputStr2 = br.readLine().split(" ");
			
			a = Integer.parseInt(inputStr2[0]);
			min = (min > a) ? a : min;
			if(N - a > 0)
				answer += (N - a);
		}
		
		answer -= (N - min);
		
		System.out.println(answer);
	}
}
