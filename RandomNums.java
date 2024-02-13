import java.util.Scanner;

public class RandomNums {
    public static void main(String[] args) throws InterruptedException {
        String k = "";
        Scanner s = new Scanner(System.in);
        while (!k.equals("stop")) {
            System.out.println("Generating Numbers");

            for (int i = 0; i < 15; i++) {
                System.out.print(".");
                Thread.sleep(500);
            }
            System.out.println("");

            int x = (int) (Math.random() * 20) + 1;
            int y = (int) (Math.random() * 20) + 1;
            System.out.println(x + " " + y);
            System.out.println("\n\n");

            k = s.nextLine();
            if (k.equals("y")) {
                System.out.println(x * y);
            }
            System.out.println("-------------------------");
        }
        s.close();
    }
}
