import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
	static int N;
	static int[][] blocks; // [N][3] 뒤에 3개는 각각 블록 종류, x, y축 위치.
	static int score;
	static int cnt;
	static Boolean[][] greenMap;
	static Boolean[][] blueMap;
	
	
	public static void main(String[] args) throws Exception{
		InitializeValues();
		GetInputs();
		SolveProblem();
		PrintAnswer();
	}
	
	public static void InitializeValues() {
		N = 0;
		score = 0;
		cnt = 0;
		greenMap = new Boolean[7][4];
		blueMap = new Boolean[4][7];
		
		for(int i=0;i<6;i++) {
			for(int j=0;j<4;j++) {
				greenMap[i][j] = false;
				blueMap[j][i] = false;
			}
		}
	}
	
	public static void GetInputs() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		
		blocks = new int[N][3];
		
		for(int i=0;i<N;i++) {
			String inputs[] = br.readLine().split(" ");
			for(int j=0;j<3;j++) {
				blocks[i][j] = inputs[j].charAt(0) - '0';
			}
		}
	}

	public static void SolveProblem() {
		
		for(int i=0;i<N;i++) {
			//System.out.println("------");
			// 1. 각 blue, green 영역에 블록 넣기.
			PutBlockInGreen(i);
			PutBlockInBlue(i);
			
			// 2. blue의 열, green 의 행이 가득 찬 경우 제거하고 점수 얻기.
			for(int j=0;j<2;j++) {
				RemoveLineInGreen();
				RemoveLineInBlue();
			}

			// 4. 넘치는 블록 내리기.
			for(int j=0;j<2;j++) {
				if(IsGreenOverflowing())
					MoveBlocksInGreen(5);
				
				if(IsBlueOverflowing())
					MoveBlocksInBlue(5);
			}
			//PrintGreenMap();
		}
		BlocksCount();
	}
	
	public static void PutBlockInGreen(int blockIdx) {
		int blockKind = blocks[blockIdx][0];
		int blockRow = 0;
		int blockCol = blocks[blockIdx][2];
		
		switch(blockKind) {
		case 1:
			while(!greenMap[blockRow][blockCol]) {
				blockRow++;
				if(blockRow > 5)
					break;
			}
			greenMap[blockRow - 1][blockCol] = true;
			break;
		case 2:
			while(!(greenMap[blockRow][blockCol] || greenMap[blockRow][blockCol+1])) {
				blockRow++;
				if(blockRow > 5)
					break;
			}
			greenMap[blockRow-1][blockCol] = true;
			greenMap[blockRow-1][blockCol+1] = true;
			break;
		case 3:
			while(!greenMap[blockRow+1][blockCol]) {
				blockRow++;
				if(blockRow + 1 > 5)
					break;
			}
			greenMap[blockRow][blockCol] = true;
			greenMap[blockRow-1][blockCol] = true;
			break;
		default:
			System.out.println("ERROR : Invalid BlockKind on Green");
		}
	}
	
	public static void PutBlockInBlue(int blockIdx) {
		int blockKind = blocks[blockIdx][0];
		int blockRow = blocks[blockIdx][1];
		int blockCol = 0;
		
		switch(blockKind) {
		case 1:
			while(!blueMap[blockRow][blockCol]) {
				blockCol++;
				if(blockCol > 5)
					break;
			}
			blueMap[blockRow][blockCol - 1] = true;
			break;
		case 2:
			while(!blueMap[blockRow][blockCol+1]) {
				blockCol++;
				if(blockCol + 1 > 5)
					break;
			}
			blueMap[blockRow][blockCol] = true;
			blueMap[blockRow][blockCol-1] = true;
			break;
		case 3:
			while(!(blueMap[blockRow][blockCol] || blueMap[blockRow+1][blockCol])) {
				blockCol++;
				if(blockCol > 5)
					break;
			}
			blueMap[blockRow][blockCol-1] = true;
			blueMap[blockRow+1][blockCol-1] = true;
			break;
		default:
			System.out.println("ERROR : Invalid BlockKind on Blue");
		}
	}
	
	public static void RemoveLineInGreen() {
		for(int i=5;i>=2;i--) {
			if(greenMap[i][0] && greenMap[i][1] && greenMap[i][2] && greenMap[i][3]) {
				++score;
				MoveBlocksInGreen(i-1);
			}
		}
	}
	
	public static void RemoveLineInBlue() {
		for(int i=5;i>=2;i--) {
			if(blueMap[0][i] && blueMap[1][i] && blueMap[2][i] && blueMap[3][i]) {
				++score;
				MoveBlocksInBlue(i-1);
			}
		}
	}
	
	// 맨 위에서 lineIdx까지의 모든 블록을 그 아래로 보낸다.
	public static void MoveBlocksInGreen(int lineIdx) {
		for(int line = lineIdx;line>=0;line--) {
			for(int i=0;i<4;i++) {
				greenMap[line+1][i] = greenMap[line][i];
			}
		}
		for(int i=0;i<4;i++) {
			greenMap[0][i] = false;
		}
	}
	
	public static void MoveBlocksInBlue(int lineIdx) {
		for(int line = lineIdx;line>=0;line--) {
			for(int i=0;i<4;i++) {
				blueMap[i][line+1] = blueMap[i][line];
			}
		}
		for(int i=0;i<4;i++) {
			blueMap[i][0] = false;
		}
	}
	
	public static boolean IsGreenOverflowing() {
		for(int i=0;i<=1;i++) {
			for(int j=0;j<=3;j++) {
				if(greenMap[i][j])
					return true;
			}
		}
		return false;
	}
	
	public static boolean IsBlueOverflowing() {
		for(int i=0;i<=1;i++) {
			for(int j=0;j<=3;j++) {
				if(blueMap[j][i])
					return true;
			}
		}
		return false;
	}
	
	public static void PrintAnswer() {
		System.out.println(score);
		System.out.println(cnt);
	}
	
	public static void BlocksCount() {
		for(int i=2;i<=5;i++) {
			for(int j=0;j<=3;j++) {
				if(greenMap[i][j])
					cnt++;
				if(blueMap[j][i])
					cnt++;
			}
		}
	}
	
	public static void PrintGreenMap() {
		for(int i=0;i<6;i++) {
			for(int j=0;j<4;j++) {
				if(greenMap[i][j])
					System.out.printf("O");
				else
					System.out.printf("_");
			}
			System.out.println();
		}
	}
}
