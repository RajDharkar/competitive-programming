import java.io.*;

public class MITIT {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(r.readLine());
        boolean[] g = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            String s = r.readLine();
            boolean good = false;
            for (int j = 1; j < n; j++) {
                try{
                if((n-j)%2 == 0){
                    if (s.substring(j, 1+(n-1+j)/2).equals(s.substring(2+(n-1+j)/2))) {
                        good = true;
                        break;
                    }
                }
                }
                catch(Exception e){
                    break;
                }
            }
            if (good) {
                g[i] = true;
            } else {
                g[i] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (g[i]) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
    }
}
