import java.util.*;
import java.io.*;
@SuppressWarnings("unused")
class Main {
    static BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static boolean[] visited;
    static List<Integer>[] adj;
    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static void setIO(String s) throws FileNotFoundException {
        System.setIn(new FileInputStream(s + ".in"));
        System.setOut(new PrintStream(new FileOutputStream(s + ".out")));
    }


    static int readInt() throws IOException {
        return Integer.parseInt(r.readLine());
    }

    static int[] readArray(int size) throws IOException {
        int[] t_array = new int[size];
        StringTokenizer st = new StringTokenizer(r.readLine());
        for (int i = 0; i < size; i++) {
            t_array[i] = Integer.parseInt(st.nextToken());
        }
        return t_array;
    }

    static ArrayList<Integer> readArrayList(int size) throws IOException {
        ArrayList<Integer> t_arrayList = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(r.readLine());
        for (int i = 0; i < size; i++) {
            t_arrayList.add(Integer.parseInt(st.nextToken()));
        }
        return t_arrayList;
    }

    
    static void floodfill(int r, int c, int color) {
        final int MAX_N = 1000;
        int[][] grid = new int[MAX_N][MAX_N];
        int row_num = 0; // provide the appropriate row and column numbers
        int col_num = 0;
        boolean[][] visited = new boolean[MAX_N][MAX_N];
        int curr_size = 0;

        // add conditions for bounds and color check

        visited[r][c] = true;
        curr_size++;

        floodfill(r, c + 1, color);
        floodfill(r, c - 1, color);
        floodfill(r - 1, c, color);
        floodfill(r + 1, c, color);
    }

    static void dfs(int node) {
		for(int n : adj[node]){
            if(!visited[n]){
                visited[n] = true;
                dfs(n);
            }
        }
	}
    static int countConnecteddfs(int node){
        int count = 0;
        for(int i = 0; i < visited.length; i++){
            if(visited[i]){
                continue;
            }
            else{
                visited[i] = true;
                count++;
                dfs(i);
            }
        }
        return count;
    }


    public static void main(String[] args) throws FileNotFoundException {
        
        // setIO("file"); // Adjust the file name accordingly
        //int n = readInt();
        //int[] arr = readArray(n);
        // ArrayList<Integer> arr = readArrayList(n, scanner); // if you prefer ArrayList

    }
}
