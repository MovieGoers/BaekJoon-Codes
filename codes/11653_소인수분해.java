import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		while(N > 1) {
			for(int i=2;i<=N;i++) {
				if(N % i == 0) {
					N /= i;
					sb.append(String.valueOf(i)).append("\n");
					break;
				}
			}
		}
		
		System.out.println(sb);
	}
}
