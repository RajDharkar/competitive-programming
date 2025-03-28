import java.io.*;
import java.util.*;

public class SortedAdjacentDifferences{
    public static void main(String[] args) throws IOException{
        Kattio kt = new Kattio("sample");
        int t = kt.nextInt();
        while(t-- >= 0){
            int n = kt.nextInt();
            int[] arr = new int[n];
            for(int i = 0; i < n; i++){
                arr[i] = (kt.nextInt());
            }
            Arrays.sort(arr);
            Number[] numbers = new Number[n];
            numbers[0] = new Number(arr[0], Integer.MAX_VALUE);
            for(int i = 1; i < n; i++){
                numbers[i] = new Number(arr[i], arr[i] - arr[i-1]);
            }
        }
        kt.close();
    }
}
class Number implements Comparable<Number>{
    int num;
    int difference;
    public Number(int n, int difference){
        num = n;
        this.difference = difference;
    }
    public int getNumber(){
        return num;
    }
    public int getDifference(){
        return difference;
    }
    @Override
    public int compareTo(Number a){
       return Integer.compare(a.getDifference(), difference);
    }
}


class Kattio extends PrintWriter {
	private BufferedReader r;
	private StringTokenizer st;
	// standard input
	public Kattio() { this(System.in, System.out); }
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
		} catch (Exception e) {}
		return null;
	}
	public int nextInt() { return Integer.parseInt(next()); }
	public double nextDouble() { return Double.parseDouble(next()); }
	public long nextLong() { return Long.parseLong(next()); }
}

