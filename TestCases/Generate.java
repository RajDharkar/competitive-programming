import java.io.*;
import java.util.*;

public class Generate {
    private static Random random = new Random();

    // Method to generate a random integer within a specified range
    public static int generateRandomNum(long min, long max) {
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

    public static void main(String[] args) {
        int tC = 1;
        File file = new File("input"+tC+".in");
        PrintWriter pw = new PrintWriter(new FileWriter(file));
        pw.print(generateRandomNum(1, 1000000000) + " " + generateRandomNum(1, 1000000000) + " " + generateRandomNum(1, 1000000000));
        pw.flush();
        pw.close();

    }
}
