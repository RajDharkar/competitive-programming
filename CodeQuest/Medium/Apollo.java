import java.io.*;

public class Apollo {
    static BufferedReader r = new BufferedReader(InputStreamReader(System.in));
    StringTokenizer st;
    public static void main(String[] args) {
        for (int i = 0; i < n; i++) {
            solve()
        }
    }

    private static void solve() {
        double x, y, z;
        staticc st = new StringTokenizer(r.readLine());
        double x = Double.parseDouble(st.nextToken());
        y = y - 180;
        z = z - 180;
        if (x < 0) {
            x += 360;
        }
        if (y < 0) {
            y += 360;
        }
        if (z < 0) {
            z += 360;
        }
        System.out.printf("%.2f %.2f %.2f%n", x, y, z);
    }
}
