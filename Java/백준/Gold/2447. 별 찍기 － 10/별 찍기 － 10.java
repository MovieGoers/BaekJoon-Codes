import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static char[][] array;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());

        array = new char[N][N];

        for(int i=0;i<N;i++){
            Arrays.fill(array[i], ' ');
        }

        divideAndConquer(0, 0, N);

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                sb.append(array[i][j]);
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }

    static void divideAndConquer(int r, int c, int size){
        if(size == 1){
            array[r][c] = '*';
            return;
        }

        int newSize = size / 3;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) {
                if (i % 3 == 1 && j % 3 == 1)
                    array[i][j] = ' ';
                else
                    divideAndConquer(r + i * newSize, c + j * newSize, newSize);
            }
        }

    }
}