import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	
	static int DNA_count, DNA_str_size, min_dist = Integer.MAX_VALUE;
	static String[] DNAs;
	static String[] nuc = {"A", "C", "G", "T"};
	static String DNA_answer = "";
	
	public static void main(String[] args) throws Exception{
		HandleInput();
		SolveProblem();
	}
	
	static void HandleInput() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inputs[] = br.readLine().split(" ");
		DNA_count = Integer.parseInt(inputs[0]);
		DNA_str_size = Integer.parseInt(inputs[1]);
		
		DNAs = new String[DNA_count];
		
		for(int i=0;i<DNA_count;i++) {
			DNAs[i] = br.readLine();
		}
	}
	
	static void SolveProblem() {
		// 1. 모든 DNA가 만들어지는 경우를 구해서, 2. 그 Hamming Dist를 구한 다음. 3. 최소값이 나오는 경우를 저장.
		for(int i=0;i<DNA_str_size;i++) {
			int[] count = new int[4];
			int mostCharIdx = 0;
			int max = -1;
			
			for(int j=0;j<DNA_count;j++) {
				switch(DNAs[j].charAt(i)) {
				case 'A':
					count[0]++;
					break;
				case 'C':
					count[1]++;
					break;
				case 'G':
					count[2]++;
					break;
				case 'T':
					count[3]++;
					break;
				}
			}
			
			for(int j=0;j<4;j++) {
				if(max < count[j]) {
					max = count[j];
					mostCharIdx = j;
				}
			}
			
			DNA_answer += GetStringChar(mostCharIdx);
		}
		
		System.out.println(DNA_answer);
		System.out.println(GetHammingDist(DNA_answer));
	}
	
	static String GetStringChar(int idx) {
		switch(idx) {
		case 0:
			return "A";
		case 1:
			return "C";
		case 2:
			return "G";
		case 3:
			return "T";
		}
		return "";
	}
	
	static int GetHammingDist(String str) {
		int sum = 0;
		for(int i=0;i<DNA_count;i++) {
			for(int j=0;j<DNA_str_size;j++) {
				if(str.charAt(j) != DNAs[i].charAt(j)) {
					sum++;
				}
			}
		}
			
		return sum;
	}
}
