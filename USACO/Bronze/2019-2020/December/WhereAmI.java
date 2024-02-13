import java.io.*;

public class WhereAmI{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new FileReader("whereami.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("whereami.out"));
        int n = Integer.parseInt(r.readLine());
        String farm = r.readLine();
        int max = 0;
        
        for(int i = 0; i < n; i++){ //ending character
            for(int j = 0; j <= i; j++){ //starting character
                //System.out.println(farm.substring(j,i) + " " + farm.substring(i));
                if(farm.substring(j+1).indexOf(farm.substring(j, i)) != -1){
                    max = Math.max(max, farm.substring(j, i).length());
                }
            }
        }
        pw.println(max + 1);
        r.close();
        pw.close();
    }
}
