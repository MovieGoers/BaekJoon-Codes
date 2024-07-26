import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main{
	static int R, C; // 최대 길이 100.
	static boolean cheese[][];
	static boolean air[][];
	static boolean isAllMelted;
	static int time, leftovers;
	static int cheeseCnt;
	
	static final int dr[] = {-1, 1, 0, 0};
	static final int dc[] = {0, 0, -1, 1};

	static class Pos {
		int row;
		int col;
		
		public Pos(int row, int col) {
			this.row = row;
			this.col = col;
		}
	}
	
	public static void main(String[] args) throws Exception{
		SetInitials();
		HandleInput();
		SolveProblem();
		
		System.out.println(time);
		System.out.println(leftovers);
	}
	
	static void SetInitials() {
		R = 0;
		C = 0;
		time = 0;
		leftovers = 0;
		isAllMelted = false;
	}

	static void HandleInput() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input1[] = br.readLine().split(" ");
		
		R = Integer.parseInt(input1[0]);
		C = Integer.parseInt(input1[1]);
		
		cheese = new boolean[R][C];
		air = new boolean[R][C];

		for(int i=0;i<R;i++) {
			String input2[] = br.readLine().split(" ");
			for(int j=0;j<C;j++) {
				if(Integer.parseInt(input2[j]) == 0) {
					cheese[i][j] = false;
				}else {
					cheese[i][j] = true;
				}
			}
		}
	}

	static void SolveProblem() {
		CountAllCheese();
		if(cheeseCnt == 0)
			isAllMelted = true;
		
		while(!isAllMelted) {
			leftovers = cheeseCnt;
			
			SetProblemIntials();
			CalcAirArea();
			// PrintAirArea();
			
			time++;
			MeltCheese();
			CountAllCheese();
			
			// System.out.println(cheeseCnt);
			if(cheeseCnt == 0)
				break;
		}
	}

	static void SetProblemIntials() {
		// air 초기화.
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				air[i][j] = false;
			}
		}
		cheeseCnt = 0;
	}
	
	static void CalcAirArea() {
		Queue<Pos> airQ = new LinkedList<>();
		boolean visited[][] = new boolean[R][C];
		airQ.add(new Pos(0, 0));
		visited[0][0] = true;
		air[0][0] = true;
		
		while(!airQ.isEmpty()) {
			Pos current = airQ.poll();

			for(int i=0;i<4;i++) {
				int nextR = current.row + dr[i];
				int nextC = current.col + dc[i];

				if(nextR < 0 || nextC < 0 || nextR >= R || nextC >= C)
					continue;

				if(visited[nextR][nextC] || cheese[nextR][nextC])
					continue;

				visited[nextR][nextC] = true;
				air[nextR][nextC] = true;

				airQ.add(new Pos(nextR, nextC));
			}
		}
	}

	static void MeltCheese() {
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				if(cheese[i][j]) {
					for(int k=0;k<4;k++) {
						if(air[i+dr[k]][j+dc[k]]) {
							cheese[i][j] = false;
							break;
						}
					}
				}
			}
		}
	}

	static void PrintAirArea() {
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				if(air[i][j])
					System.out.print("A");
				else
					System.out.print("_");
			}
			System.out.println();
		}
	}

	static void CountAllCheese() {
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				if(cheese[i][j]) {
					cheeseCnt++;
				}
			}
		}
	}
}
