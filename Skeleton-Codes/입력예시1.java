import java.util.*;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int row, col;
	static int [][] map;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// br.readLine() 에서 string 입력 받기.
		StringTokenizer st = new StringTokenizer(br.readLine());
			
		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());
			
		map = new int [row][col];
		
		for(int i=0;i<row;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<col;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
}
