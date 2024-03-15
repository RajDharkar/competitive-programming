
import java.io.*;

public class MITIT{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(r.readLine());
        for(int i = 0; i < n; i++){
            String s = r.readLine();
            boolean good = false;
            for(int j = 1; j < n; j++){
                if(n-j+1%2 == 0){
                    if(s.substring(j, 1+(n+j)/2).equals(s.substring((2+(n+j)/2)))){
                        good = true;
                    }
                }
            }
            if(good){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
    }
}
