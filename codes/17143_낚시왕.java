import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Shark{
	int r; // 위치 row
	int c; // 위치 col
	int s; // 속력
	int d; // 방향 1위 2아래 3오른쪽 4왼쪽
	int z; // 크기
	Boolean isGone;
	
	public Shark(int r, int c, int s, int d, int z, Boolean isGone){
		this.r = r;
		this.c = c;
		this.s = s;
		this.d = d;
		this.z = z;
		this.isGone = isGone;
	}
}

public class Main{
	static StringBuilder answerSB = new StringBuilder();
	
	static int R, C, M; // R과 C는 2이상 100이하.상어 수는 0이상 RxC이하
	static ArrayList<Shark> sharks;
	static int[][] map;
	
	static int answer;

	public static void main(String[] args) throws Exception{
		InitializeValues();
		GetInputs();
		SolveProblem();
		PrintAnswer();
	}
	
	public static void InitializeValues() {
		answer = 0;
	}
	
	public static void GetInputs() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inputs[] = br.readLine().split(" ");

		R = Integer.parseInt(inputs[0]);
		C = Integer.parseInt(inputs[1]);
		M = Integer.parseInt(inputs[2]);

		sharks = new ArrayList<>();
		map = new int[R+1][C+1];

		for(int i=0;i<M;i++) {
			String inputs2[] = br.readLine().split(" ");
			int r = Integer.parseInt(inputs2[0]);
			int c = Integer.parseInt(inputs2[1]);
			int s = Integer.parseInt(inputs2[2]);
			int d = Integer.parseInt(inputs2[3]);
			int z = Integer.parseInt(inputs2[4]);
			sharks.add(new Shark(r, c, s, d, z, false));
		}
	}

	public static void SolveProblem() {
		for(int i=1;i<=C;i++) {
			DrawMap();
			//PrintMap();
			CatchShark(i);
			MoveSharks();
			//PrintSharkInfos(i);
			//System.out.printf("--- %d ---\n", i);
		}
	}
	
	public static void DrawMap() {
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				map[i][j] = -1;
			}
		}
		
		for(int i=0;i<M;i++) {
			Shark sh = sharks.get(i);
			
			if(sh.isGone)
				continue;
			
			// 이미 어떤 상어가 있는 경우,
			if(map[sh.r][sh.c] != -1) {
				if(sharks.get(map[sh.r][sh.c]).z < sh.z) {
					// 현재 고려중인 상어가 크기가 더 큰 경우.
					sharks.get(map[sh.r][sh.c]).isGone = true;
					map[sh.r][sh.c] = i;
				}else {
					// 이미 있는 상어가 더 큰 경우.
					sh.isGone = true;
				}
			}else {
				// 현재 위치에 상어가 없는 경우,
				map[sh.r][sh.c] = i;
			}
		}
	}
	
	public static void PrintMap() {
		for(int i=1;i<=R;i++) {
			for(int j=1;j<=C;j++) {
				System.out.printf("%d  ", map[i][j]);
			}
			System.out.println();
		}
	}

	public static void MoveSharks() {
		for(int i=0;i<M;i++) {
			Shark sh = sharks.get(i);
			
			if(sh.isGone)
				continue;
			
			int time = sh.s;
			
			for(int j=0;j<time;j++) {
				switch(sh.d) {
				case 1:
					// 방향 위
					if(sh.r <= 1) {
						sh.d = 2;
						sh.r = 2;
					}else {
						--sh.r;
					}
					break;
				case 2:
					// 방향 아래.
					if(sh.r >= R) {
						sh.d = 1;
						sh.r = R - 1;
					}else {
						++sh.r;
					}
					break;
				case 4:
					// 방향 왼쪽.
					if(sh.c <= 1) {
						sh.d = 3;
						sh.c = 2;
					}else {
						--sh.c;
					}
					break;
				case 3:
					// 방향 오른쪽.
					if(sh.c >= C) {
						sh.d = 4;
						sh.c = C - 1;
					}else {
						++sh.c;
					}
					break;
				default:
				}
			}
		}
	}
	
	public static void CatchShark(int pos) {
		for(int i=1;i<=R;i++) {
			if(map[i][pos] != -1) {
				sharks.get(map[i][pos]).isGone = true;
				answer += sharks.get(map[i][pos]).z;
				break;
			}
		}
	}
	
	public static void PrintAnswer() {
		System.out.println(answer);
	}
	
	public static void PrintSharkInfos(int count) {
		System.out.printf("--- %d ---\n", count);
		for(int i=0;i<M;i++) {
			System.out.printf("%d번째 상어 : (%d, %d, %d, %d, %d)\n", i, sharks.get(i).r, sharks.get(i).c, sharks.get(i).s, sharks.get(i).d, sharks.get(i).z);
		}
	}
}
