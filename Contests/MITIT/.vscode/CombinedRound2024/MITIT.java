import java.io.*;
import java.util.*;

public class MITIT {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(r.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        long maxMeet = 0;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(r.readLine());
            long t = Long.parseLong(st.nextToken());
            long a = Long.parseLong(st.nextToken());
            long time = m - t;
            time = (time + a - 1) / a;
            maxMeet = Math.max(maxMeet, time+1);
            //System.out.println(time);
        }
        System.out.println(maxMeet);
    }
}
