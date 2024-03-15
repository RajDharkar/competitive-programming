
import java.util.*;
import java.io.*;

class LemonadeLine {
  // CHANGE ME! (for old usaco)
  public static void main(String[] args) throws IOException {
    Kattio sc = new Kattio("line");

    int n = sc.nextInt();
    int m = sc.nextInt();
    int arr[] = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = sc.nextInt();
    }
    Arrays.sort(arr);
    //int ans =0;
    for(int i = 1; i < 1000; i++){
        int bucketAmount = 0;
        for(int j = 0; j < n; j++){
            bucketAmount+=n/i;
        }
        if(bucketAmount < m/2){
            continue;
        }
        int[] mod = new int[n];
        for(int k = 0; k < n; k++){
            mod[k] = arr[k]%i;
        }
        Arrays.sort(mod);
        for(int k = 0; k < n; k++){

        }
    }
    sc.println();
    sc.close();
  }

  static class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;

    // standard input
    public Kattio() {
      this(System.in, System.out);
    }

    public Kattio(InputStream i, OutputStream o) {
      super(o);
      r = new BufferedReader(new InputStreamReader(i));
    }

    // USACO-style file input
    public Kattio(String problemName) throws IOException {
      super(problemName + ".out");
      r = new BufferedReader(new FileReader(problemName + ".in"));
    }

    // returns null if no more input
    public String next() {
      try {
        while (st == null || !st.hasMoreTokens())
          st = new StringTokenizer(r.readLine());
        return st.nextToken();
      } catch (Exception e) {
      }
      return null;
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}