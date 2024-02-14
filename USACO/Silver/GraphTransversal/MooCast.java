import java.util.*;
import java.io.*;

public class MooCast {
    static List<Integer>[] adj;
    static boolean[] visited;
    static int count = 0;
    public static double distance(int x, int y, int x2, int y2){
        return Math.sqrt(Math.pow(x2-x,2) + Math.pow(y2-y, 2));
    }
    static int dfs(int node){
        for(int a : adj[node]){
            if(!visited[a]){
                count++;
                visited[a] = true;
                dfs(a);
            }
        }
        return count;
    }
    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new FileReader("moocast.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("moocast.out"));
        // BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        // PrintWriter pw = new PrintWriter(System.out);
        int n = Integer.parseInt(r.readLine());
        adj = new ArrayList[n];
        visited = new boolean[n];
        int[][] px = new int[3][n];
        for(int i = 0; i < n; i++){
            adj[i] = new ArrayList<Integer>();
            StringTokenizer st = new StringTokenizer(r.readLine());
            for(int j = 0; j < 3; j++)
                px[j][i] = Integer.parseInt(st.nextToken());
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j!=i){
                    if(distance(px[0][i],px[1][i],px[0][j],px[1][j]) <= px[2][i]){
                        adj[i].add(j);
                    }
                }
            }
        }
        int max = 0;
        for(int i = 0; i < n; i++){
            visited = new boolean[n];
            visited[i] = true;
            count = 1;
            max = Math.max(max, dfs(i)); 
        }
        pw.println(max);
        pw.close();
        r.close();
    }
}
