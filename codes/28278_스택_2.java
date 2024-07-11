import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.util.Stack;


public class Main {
	public static void main(String[] args) throws Exception{
		new Main().solution();
	}

	private void solution() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		Stack<Integer> stackInt = new Stack<>();
		
		int N = Integer.parseInt(st.nextToken());

		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int inst = Integer.parseInt(st.nextToken());
			switch(inst) {
			case 1:
				int value = Integer.parseInt(st.nextToken());
				stackInt.push(value);
				break;
			case 2:
				if(stackInt.isEmpty())
					bw.write("-1");
				else
					bw.write(String.valueOf(stackInt.pop()));
				bw.newLine();
				break;
			case 3:
				bw.write(String.valueOf(stackInt.size()));
				bw.newLine();
				break;
			case 4:
				if(stackInt.isEmpty())
					bw.write("1");
				else
					bw.write("0");
				bw.newLine();
				break;
			case 5:
				if(stackInt.isEmpty())
					bw.write("-1");
				else
					bw.write(String.valueOf(stackInt.peek()));
				bw.newLine();
				break;
			}
		}
		
		// bw.write(), bw.newLine()
		bw.flush();
		bw.close();
	}
}
