import java.util.*;
import java.io.*;

public class ClosingTheFarm {
    static List<Integer>[] adj;
    static boolean[] visited;
    static boolean[] closed;
    static int count = 0;
    static int dfs(int node){
        for(int a : adj[node]){
            if(!closed[a]){
                if(!visited[a]){
                    count++;
                    visited[a] = true;
                    dfs(a);
                }
            }
        }
        return count;
    }
    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException{
        // BufferedReader r = new BufferedReader(new FileReader("closing.in"));
        // PrintWriter pw = new PrintWriter(new FileWriter("closing.out"));
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(r.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        adj = new ArrayList[n];
        for(int i = 0; i < n; i++){
            adj[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < m; ++i){
            st = new StringTokenizer(r.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a-1].add(b-1);
            adj[b-1].add(a-1);
        }
        closed = new boolean[n];
        for(int i = 0; i < n; i++){
            count = 1;
            visited = new boolean[n];
            int firstopen = -1;
            for(int letter = 0; letter < n; letter++){
                if(!closed[letter]){
                    firstopen = letter;
                    break;
                }
            }
            visited[firstopen] = true;
            if(dfs(firstopen) == (n-i)){
                pw.println("YES");
            }
            else{
                pw.println("NO");
            }
            int k = Integer.parseInt(r.readLine());
            closed[k-1] = true;
            
        }
        
        pw.close();
        r.close();
    }
}
