import java.util.*;
import java.io.*;

public class HoofBall{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new FileReader("hoofball.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(new File("hoofball.out")));
        int n = Integer.parseInt(r.readLine());
        int cows[] = new int[n];
        StringTokenizer st = new StringTokenizer(r.readLine());
        for(int i = 0; i < n; i++){
            cows[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(cows);
        int ans = 0;
        int difbef = 0;
        int i = 0;
        while(i<n-1){
            if((cows[i+1] - cows[i]) >= difbef){
                ans++;
            }
            difbef = cows[i+1] - cows[i];
            i++;
        }
        int otherans = 0;
        i = n-1;
        difbef = 0;
        while(i>0){
            if((cows[i] - cows[i-1]) >= difbef){
                otherans++;
            }
            difbef = cows[i] - cows[i-1];
            i--;
        }
        pw.println(Math.min(ans, otherans));
        pw.close();
        r.close();
    }
}
