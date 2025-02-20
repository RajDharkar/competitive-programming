import java.util.*;
import java.io.*;

public class Template{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        ArrayList<Integer> a = new ArrayList<>(); //https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html
        a.add(4);
        int n = Integer.parseInt(r.readLine());
        
        int ans = n;
        pw.println(ans);
        pw.close();
    }
}
