import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
	public static void main(String[] args) throws Exception{
		new Main().solution();
	}

	private void solution() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int n = Integer.parseInt(st.nextToken());
		HashMap<String, Boolean> log = new HashMap<String, Boolean>();

		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			String command = st.nextToken();
			
			if(command.equals("enter")) {
				log.put(name, true);
			}else if(command.equals("leave")) {
				if(log.containsKey(name)) {
					log.remove(name);
				}
			}else {
				System.out.println("ERROR # 1");
			}
		}
		
		ArrayList<String> strList = new ArrayList<String>(log.keySet());
		Collections.sort(strList, Collections.reverseOrder());

		for(String str : strList) {
			sb.append(str).append("\n");
		}
		System.out.println(sb);
	}
}
