import java.io.*;
import java.util.*;

public class TrominoPacking {
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(r.readLine());
        for(int i = 0; i < t; i++){
            solve();
        }
        
    }
    public static void solve() throws IOException{
        StringTokenizer st = new StringTokenizer(r.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] grid = new char[n][m];
        String s;
        for(int i = 0; i < n; i++){
            s = r.readLine();
            for(int j = 0; j < m; j++){
                grid[i][j] = s.charAt(j);
            }
        }
        long ans = 1;
        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                if(grid[i][j] == 'o'){
                    int count = 4;
                    if(grid[i][j+1] == '#' || grid[i+1][j] == '#'){
                        count--;
                    }
                    if(grid[i+1][j] == '#' || grid[i][j-1] == '#'){
                        count--;
                    }
                    if(grid[i-1][j] == '#' || grid[i][j-1] == '#'){
                        count--;
                    }
                    if(grid[i-1][j] == '#' || grid[i][j+1] == '#'){
                        count--;
                    }
                    if(count!=0){
                        ans*=count;
                    }
                }
            }
        }
        System.out.println(ans%(1000000000 + 7));
    }
}
