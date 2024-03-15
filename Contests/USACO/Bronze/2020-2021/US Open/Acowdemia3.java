import java.io.*;

public class Acowdemia3{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter pw = new PrintWriter(System.out);
        //StringTokenizer st = new StringTokenizer(r.readLine());
        int n = Integer.parseInt(r.readLine());
        int m = Integer.parseInt(r.readLine());
        char[][] cows = new char[n][m];
        for(int i = 0; i < n; i++){
            String l = r.readLine();
            for(int j = 0; j < m; j++){
                cows[i][j] = l.charAt(j);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(cows[i][j] == 'G'){
                    
                }
            }
        }
    }
    
}
