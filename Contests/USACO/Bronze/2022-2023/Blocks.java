import java.io.*;

public class Blocks{
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException{
        int n = Integer.parseInt(r.readLine());
        String a = r.readLine();
        String b = r.readLine();
        String c = r.readLine();
        String d = r.readLine();
        for(int i = 0; i < n; i++){
            if(solve(a, b, c, d)){
                pw.println("YES");
            }
            else{
                pw.println("NO");
            }
        }
        pw.close();
    }
    public static boolean solve(String a,String b,String c,String d){
        
        return true;
    }
}
