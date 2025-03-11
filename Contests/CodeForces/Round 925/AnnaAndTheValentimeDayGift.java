
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.io.PrintWriter;
public class AnnaAndTheValentimeDayGift {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
		int t = Integer.parseInt(r.readLine());
        for(int a = 0; a < t; a++){
            StringTokenizer st = new StringTokenizer(r.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(r.readLine());
            String[] arr = new String[n];
            long size = 0;
            for(int i = 0; i < n; i++){
                arr[i] = st.nextToken();
                size+=arr[i].length();
            }
            ArrayList<Integer> list = new ArrayList<>();
            for(String i : arr){
                list.add(Integer.numberOfTrailingZeros(Integer.parseInt(i)));
            }
            Collections.sort(list, Collections.reverseOrder());
            int subtractsize = 0;
            for(int i = 0; i < list.size(); i++){
                if(i % 2 == 1){
                    subtractsize+=i;
                }
            }
            if(size - subtractsize >= m){
                pw.println("Sasha");
            }
            else{
                pw.println("Anna");
            }
        }
	}
}