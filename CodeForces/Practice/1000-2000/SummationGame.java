import java.io.*;
import java.util.*;

public class SummationGame{
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException{
        int t = Integer.parseInt(r.readLine());
        for(int i = 0; i < t; i++){
            solve();
        }
        pw.flush();
        pw.close();
    }
    public static void solve() throws IOException{
        StringTokenizer st = new StringTokenizer(r.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int[] num = new int[n];
        st = new StringTokenizer(r.readLine());
        int beforePXSum = 0;
        int pK = n, pX = n - x;
        int ans = 0;
        int afterPXSum = 0;
        for(int i = 0; i < n; i++){
            num[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(num);
        for(int i = 0; i < n; i++){
            if(i<pX){
                beforePXSum+=num[i];
            }
            else{afterPXSum+=num[i];}
        }
        
        //pw.println(beforePXSum + " " + sum);
        if(n == k && k == x){
            pw.println(0);
            return;
        }
        ans = beforePXSum-afterPXSum;
        pw.println(beforePXSum + " " + afterPXSum);
        // pw.println(ans);
        for(int i = 0; i < k; i++){
            pK--;
            pX--;
            if(pX == -1 || pK == -1){
                break;
            }
            beforePXSum-=num[pX];
            afterPXSum+=num[pX];
            //afterPXSum-=num[pK];
            pw.println(beforePXSum + " " + afterPXSum);
            
            //System.out.println(beforePXSum - afterPXSum);
            ans = Math.max(ans, beforePXSum - afterPXSum);
        }
        pw.println(ans);
    }
}