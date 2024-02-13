import java.util.*;
import java.io.*;

public class aplusb{
    public static void main(String[] args) throws IOException{
         BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
         StringTokenizer st = new StringTokenizer(r.readLine());
         int a = Integer.parseInt(st.nextToken());
         int b = Integer.parseInt(st.nextToken());
         int c = Integer.parseInt(r.readLine());
         if(c == 0){
            System.out.println(a + b);
         }
         else{
            System.out.println(a*b);
         }
    }
}