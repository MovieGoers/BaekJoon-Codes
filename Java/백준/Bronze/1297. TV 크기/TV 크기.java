import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine().trim());

        int D, H, W;

        D = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        double ratio = Math.sqrt(H * H + W * W);

        System.out.printf("%d %d", (int) (D / ratio * H), (int) (D / ratio * W));
    }
}