import java.util.*;
import java.io.*;

public class Acowdemia2 {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(r.readLine());
        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        HashMap<String, Integer> index = new HashMap<>();
        StringTokenizer ap = new StringTokenizer(r.readLine());

        for (int i = 0; i < n; i++) {
            String s = ap.nextToken();
            index.put(s, i);
        }
         char[][] ans = new char[n][n];
        for (int a = 0; a < n; a++) {
            Arrays.fill(ans[a], '?');
            ans[a][a] = 'B';
        }
       

        for (int a = 0; a < k; a++) {
            String[] names = new String[n];
            StringTokenizer tk = new StringTokenizer(r.readLine());

            for (int i = 0; i < n; i++) {
                names[i] = tk.nextToken();
            }

            for (int i = 0; i < n; i++) {
                boolean alphabetical = true;
                for (int j = i + 1; j < n; j++) {
                    int jindex = index.get(names[j]);
                    int previndex = index.get(names[i]);

                    if (names[j-1].compareTo(names[j]) > 0) {
                        alphabetical = false;
                    }
                    if (!alphabetical) {
                            ans[jindex][previndex] = '1';
                            ans[previndex][jindex] = '0';
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    System.out.print(ans[i][j]);
                } else {
                    System.out.print('B');
                }
            }
            System.out.println("");
        }

        pw.close();
    }
}
