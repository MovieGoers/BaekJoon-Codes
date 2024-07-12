import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

class Pos{
	int row;
	int col;
	int brokeWall;
	
	Pos(int r, int c, int bw){
		this.row = r;
		this.col = c;
		this.brokeWall = bw;
	}
}

public class Main {
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	static int row, col, answer = -1;
	static int[][] map;
	static int[][][] visited;
	
	public static void main(String[] args) throws Exception{
		new Main().solution();
	}

	private void solution() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] inputs = br.readLine().split(" ");
		row = Integer.parseInt(inputs[0]);
		col = Integer.parseInt(inputs[1]);
		
		map = new int[row][col];
		visited = new int[row][col][2];
		
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				visited[i][j][0] = 0;
				visited[i][j][1] = 0;
			}
		}
		visited[0][0][0] = 1;

		
		for(int i=0;i<row;i++) {
			String input = br.readLine();
			for(int j=0;j<col;j++) {
				map[i][j] = input.charAt(j) - '0';
			}
		}

		DoBFS();
		
		System.out.println(answer);
	}
	
	private void DoBFS() {
		Queue<Pos> Q = new LinkedList<>();
		Q.add(new Pos(0, 0, 0)); // (0,0) 좌표에 벽을 아직 제거하지 않은 상태.
		
		while(!Q.isEmpty()) {
			Pos cur = Q.poll();
			
			if(cur.row == row - 1 && cur.col == col - 1) {
				answer = visited[cur.row][cur.col][cur.brokeWall];
				return;
			}
			
			for(int i=0;i<4;i++) {
				int newR = cur.row + dr[i];
				int newC = cur.col + dc[i];
				
				// 범위 밖
				if(newR < 0 || newC < 0 || newR >= row || newC >= col)
					continue;
				
				// 이미 방문한 적이 있는 경우.
				if(visited[newR][newC][cur.brokeWall] > 0)
					continue;
				
				// 벽이 없는 경우 기존 state 유지한체로 다음 이동.
				if(map[newR][newC] == 0) {
					visited[newR][newC][cur.brokeWall] = visited[cur.row][cur.col][cur.brokeWall] + 1;
					Q.add(new Pos(newR, newC, cur.brokeWall));
				}

				// 벽이 있지만 제거하지 않은 경우 state 변경 후 이동.
				if(map[newR][newC] == 1 && cur.brokeWall == 0) {
					visited[newR][newC][1] = visited[cur.row][cur.col][0] + 1;
					Q.add(new Pos(newR, newC, cur.brokeWall + 1));
				}
			}
		}
	}
}
