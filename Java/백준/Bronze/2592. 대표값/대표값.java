import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<Integer, Integer> map = new HashMap<>();

        int sum = 0;
        for(int i=0;i<10;i++){
            int value = Integer.parseInt(br.readLine().trim());

            sum += value;
            map.put(value, map.getOrDefault(value, 0) + 1);
        }

        int freq = 0;
        int freqValue = 0;
        for(Map.Entry<Integer, Integer> entry : map.entrySet()){
            if(freq < entry.getValue()){
                freq = entry.getValue();
                freqValue = entry.getKey();
            }
        }
        System.out.printf("%d\n%d", sum / 10, freqValue);
    }
}