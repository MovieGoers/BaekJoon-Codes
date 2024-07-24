import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
	static int R, C;
	static char[][] map;
	static boolean[] visited = new boolean[26];
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	static int answer = 0;
	
	public static void main(String[] args) throws Exception{
		HandleInput();
		SolveProblem();
	}

	static void HandleInput() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inputs[] = br.readLine().split(" ");

		R = Integer.parseInt(inputs[0]);
		C = Integer.parseInt(inputs[1]);
		
		map = new char[R][C];
		
		for(int i=0;i<R;i++) {
			String input = br.readLine();
			for(int j=0;j<C;j++) {
				map[i][j] = input.charAt(j);
			}
		}
	}

	static void SolveProblem() {
		visited[map[0][0] - 'A'] = true;
		DoDFS(0, 0, 1);
		
		
		System.out.println(answer);
	}
	
	static void DoDFS(int row, int col, int cnt) {
		answer = (answer < cnt) ? cnt : answer;
		
		for(int i=0;i<4;i++) {
			int nextR = row + dr[i];
			int nextC = col + dc[i];
			
			if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C)
				continue;
			
			if(visited[map[nextR][nextC] - 'A'])
				continue;
			
			visited[map[nextR][nextC] - 'A'] = true;
			DoDFS(nextR, nextC, cnt + 1);
			visited[map[nextR][nextC] - 'A'] = false;
		}
	}
}
