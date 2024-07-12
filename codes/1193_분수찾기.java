import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception{
		new Main().solution();
	}

	private void solution() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int n = Integer.parseInt(br.readLine());
		
		// 1/1 -> 1/2 -> 2/1 -> 3/1 -> 2/2 -> 1/3 -> ..
		int baseCnt = 1, cnt;
		Boolean flag = true;
		Boolean flag2 = false;
		while(true) {
			cnt = baseCnt;
			if(flag) {
				while(cnt > 0) {
					if(n <= 1) {
						sb.append(cnt);
						sb.append("/");
						sb.append(baseCnt - cnt + 1);
						sb.append("\n");
						flag2 = true;
						break;
					}
					--cnt;
					--n;
				}
			}else {
				while(cnt > 0) {
					if(n <= 1) {
						sb.append(baseCnt - cnt + 1);
						sb.append("/");
						sb.append(cnt);
						sb.append("\n");
						flag2 = true;
						break;
					}
					--cnt;
					--n;
				}
			}
			if(flag2)
				break;
			flag = !flag;
			baseCnt++;
		}
		System.out.println(sb);
	}
}
