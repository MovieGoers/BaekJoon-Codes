import java.util.*;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Position{
	private int row;
	private int col;
	private int time;

	public Position(int r, int c, int t) {
		this.row = r;
		this.col = c;
		this.time = t;
	}

	public int GetRow() {
		return this.row;
	}

	public int GetCol() {
		return this.col;
	}
	
	public int GetTime() {
		return this.time;
	}
}

public class Main {
	static int row, col;
	static int [][] map;
	static int [] dr= {0, 0, -1, 1}, dc = {1, -1, 0, 0};
	static boolean [][] visited;
	static int answer = 0;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// br.readLine() 에서 string 입력 받기.
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());
			
		map = new int [row][col];
		visited = new boolean[row][col];
		
		for(int i=0;i<row;i++) {
			String inputStr = br.readLine();
			for(int j=0;j<col;j++) {
				map[i][j] = inputStr.charAt(j) - '0';
			}
		}
		
		DoBFS();
		System.out.println(answer + 1);
		// PrintMap();
		
	}
	public static void DoBFS() {
		Queue<Position> Q = new LinkedList<>();
		Q.offer(new Position(0, 0, 0));
		visited[0][0] = true;
		
		while(!Q.isEmpty()) {
			Position current = Q.poll();
			int currentRow = current.GetRow();
			int currentCol = current.GetCol();
			int currentTime = current.GetTime();
			
			if(currentRow == row - 1 && currentCol == col - 1) {
				answer = currentTime;
				return;
			}
			
			for(int i=0;i<4;i++) {
				int newRow = currentRow + dr[i];
				int newCol = currentCol + dc[i];
				
				if(newRow < 0 || newCol < 0 || newRow >= row || newCol >= col)
					continue;
				
				if(visited[newRow][newCol] || map[newRow][newCol] == 0)
					continue;
				
				visited[newRow][newCol] = true;
				Q.offer(new Position(newRow, newCol, currentTime + 1));
			}
			
		}
	}
}
