import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Deque;
import java.util.LinkedList;

public class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		Deque<Integer> dq = new LinkedList<>();
		
		int command = 0, value = 0;
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i=0;i<N;i++) {
			String inputStr = br.readLine();
			st = new StringTokenizer(inputStr, " ");
			
			command = Integer.parseInt(st.nextToken());
			switch(command) {
			case 1:
				value = Integer.parseInt(st.nextToken());
				dq.addFirst(value);
				break;
			case 2:
				value = Integer.parseInt(st.nextToken());
				dq.addLast(value);
				break;
			case 3:
				if(!dq.isEmpty()) {
					sb.append(dq.pollFirst()).append('\n');
				}else {
					sb.append("-1\n");
				}
				break;
			case 4:
				if(!dq.isEmpty()) {
					sb.append(dq.pollLast()).append('\n');
				}else {
					sb.append("-1\n");
				}
				break;
			case 5:
				sb.append(dq.size()).append('\n');
				break;
			case 6:
				if(!dq.isEmpty()) {
					sb.append("0\n");
				}else {
					sb.append("1\n");
				}
				break;
			case 7:
				if(!dq.isEmpty()) {
					sb.append(dq.getFirst()).append('\n');
				}else {
					sb.append("-1\n");
				}
				break;
			case 8:
				if(!dq.isEmpty()) {
					sb.append(dq.getLast()).append('\n');
				}else {
					sb.append("-1\n");
				}
				break;
			default:
					System.out.println("ERROR! #1");
					return;
			}
		}
		System.out.println(sb);
	}
}
