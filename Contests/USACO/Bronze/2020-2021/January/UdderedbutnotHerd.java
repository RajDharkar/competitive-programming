import java.io.*;

public class UdderedbutnotHerd{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        String alphabet = r.readLine();
        String cowalphabet = r.readLine();
        int ans = 1;
        for(int i = 1; i < cowalphabet.length(); i++){
            if(alphabet.indexOf(cowalphabet.charAt(i)) <= alphabet.indexOf(cowalphabet.charAt(i-1))){
                ans++;
            }
        }
        pw.println(ans);
        pw.close();
    }
}
