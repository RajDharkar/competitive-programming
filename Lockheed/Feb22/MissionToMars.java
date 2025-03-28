import java.util.Scanner;

public class MissionToMars {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int cases = Integer.parseInt(in.nextLine());
        for (int c = 0; c < cases; c++) {
            double distance = in.nextDouble()*1e6; // in millions of miles
            double speed = in.nextDouble(); // in miles per hour
            in.nextLine();

            System.out.println(distance + " " + speed);
            System.out.println(distance / speed);
        }
        in.close();
    }
}
