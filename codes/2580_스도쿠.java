import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Stack;

class Zero{
	int row;
	int col;
	
	Zero(int r, int c){
		this.row = r;
		this.col = c;
	}
}

public class Main{
	static char board[][];
	static Stack<Zero> zeroes = new Stack<>();
	static Boolean isDone = false;

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		board = new char[9][9];

		for(int i=0;i<9;i++) {
			String inputStrs[] = br.readLine().split(" ");
			for(int j=0;j<9;j++) {
				board[i][j] = inputStrs[j].charAt(0);
				if(board[i][j] == '0') {
					zeroes.add(new Zero(i, j));
				}
			}
		}
		//PrintBoard();
		DoDFS();
	}
	
	public static Boolean CheckIfCorrect(int row, int col, char value) {
		for(int i=0;i<9;i++) {
			if(board[row][i] == value && col != i) {
				return false;
			}
			
			if(board[i][col] == value && row != i) {
				return false;
			}
		}
		
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(board[i + (row / 3) * 3][j + (col / 3) * 3] == value) {
					if(!(row == i + (row / 3) * 3 && col == j + (col / 3) * 3))
						return false;
				}
			}
		}
		
		return true;
	}

	public static void DoDFS() {
		if(isDone)
			return;
		
		if(zeroes.isEmpty()) {
			PrintBoard();
			isDone = true;
			return;
		}

		Zero curr = zeroes.pop();
		for(int i = 1;i<=9;i++) {
			if(!CheckIfCorrect(curr.row, curr.col, (char)('0' + i)))
				continue;
			
			board[curr.row][curr.col] = (char)('0' + i);
			DoDFS();
			board[curr.row][curr.col] = '0';
			
		}
		zeroes.push(curr);
	}

	public static void PrintBoard() {
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<9;i++) {
			for(int j=0;j<9;j++) {
				sb.append(board[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
}
