import java.util.*;
import java.io.*;

public class CowtactTracing2{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        ArrayList<Integer> sets = new ArrayList<>(); //https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html
        int n = Integer.parseInt(r.readLine());
        String s = r.readLine();
        s+="0";
        int length = 0;
        for(int i = 0; i < n+1; i++){
            if(s.charAt(i) == '0' && length!=0){
                sets.add(length);
                length = 0;
            }
            else if(s.charAt(i) == '1'){
                length++;
            }
        }
        if(sets.size() == 0){
            System.out.println(0); //hello test case 3
            System.exit(0);
        }
        int nights = 1000000;
        for(int i = 0; i < sets.size(); i++){
            if(i == 0 || i == sets.size()-1){
                nights = Math.min(nights, sets.get(i) - 1);
            }
            else{
                nights = Math.min(nights, (int)Math.ceil(sets.get(i)/2.0));
            }
        }
        int ans = 0;
        for(int i = 0; i < sets.size(); i++){
                ans+=Math.ceil((double)(sets.get(i) )/(2 * (nights) + 1));
        }
        pw.println(ans);

        pw.close();
    }
}
