import java.io.*;
import java.util.*;

public class Generate {
    private static Random random = new Random();

    // Method to generate a random integer within a specified range
    public static long generateRandomNum(long min, long max) {
        return random.nextLong(max - min + 1) + min;
    }

    // Method to generate a random character from a given set of characters
    public static char generateRandomChar(char[] characters) {
        return characters[random.nextInt(characters.length)];
    }

    // Method to generate a random boolean value
    public static boolean generateRandomBoolean() {
        return random.nextBoolean();
    }

    // Method to generate a random double value between 0.0 and 1.0
    public static double generateRandomDouble() {
        return random.nextDouble();
    }

    // Method to generate a random long integer
    public static long generateRandomLong() {
        return random.nextLong();
    }
    public static int retInt(){
        return (int)generateRandomNum(1, 100000);
    }
    public static void main(String[] args) throws IOException{
        int[] ns = {3, 5, 10, 1000, 1000, 1000, 10000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000};
        for(int tC = 1; tC < ns.length; tC++){
            File file = new File("input"+(tC+1)+".txt");
            PrintWriter pw = new PrintWriter(new FileWriter(file));
            int n = ns[tC];
            pw.println(n);
            for(int i = 0; i < n-1; i++){
                pw.print(generateRandomNum(1, n * n) + " ");
            }
            pw.println(generateRandomNum(1, n * n));
            pw.flush();
            pw.close();
            BufferedReader r = new BufferedReader(new FileReader("input"+(tC+1)+".txt"));
            pw = new PrintWriter(new FileWriter(new File("output" + (tC+1)+".txt")));
            n = Integer.parseInt(r.readLine());
            int[] arr = new int[n];
            StringTokenizer st = new StringTokenizer(r.readLine());
            for(int i = 0; i < n; i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(arr);
            ArrayList<Integer> ar = new ArrayList<>();
            for(int i = n-1; i>=0; i--){
                ar.add(arr[i]);
            }
            //400, 7, 2, 2, 1
            int ans = 0;
            for(int i = 0; i < n; i++){
                if(ar.get(i) >= i){
                    ans++;
                }
                else{
                    break;
                }
            }
            pw.println(ans);
            pw.flush();
            pw.close();
            r.close();
        }
    }
}
