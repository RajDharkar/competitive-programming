import java.io.*;
import java.util.*;

public class Moorbles {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter writer = new PrintWriter(System.out);
    static int boxes, rounds, guesses;
    static int[][] predictionScores;
    static boolean isSolved;
    static int[] moveSequence;

    public static void main(String[] args) throws IOException {
        int testCases = Integer.parseInt(reader.readLine().trim());
        for (int test = 0; test < testCases; test++) {
            readInput();
            solveProblem();
            writer.flush();
        }
        reader.close();
        writer.close();
    }

    static void readInput() throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        boxes = Integer.parseInt(tokenizer.nextToken());
        rounds = Integer.parseInt(tokenizer.nextToken());
        guesses = Integer.parseInt(tokenizer.nextToken());
        predictionScores = new int[2][rounds];
        moveSequence = new int[rounds];

        for (int i = 0; i < rounds; i++) {
            int oddCount = 0, evenCount = 0;
            int maxOdd = Integer.MIN_VALUE, minOdd = Integer.MAX_VALUE;
            int maxEven = Integer.MIN_VALUE, minEven = Integer.MAX_VALUE;

            StringTokenizer roundTokenizer = new StringTokenizer(reader.readLine());
            for (int j = 0; j < guesses; j++) {
                int marble = Integer.parseInt(roundTokenizer.nextToken());
                if (marble % 2 == 0) {
                    evenCount++;
                    maxEven = Math.max(maxEven, marble);
                    minEven = Math.min(minEven, marble);
                } else {
                    oddCount++;
                    maxOdd = Math.max(maxOdd, marble);
                    minOdd = Math.min(minOdd, marble);
                }
            }

            if (oddCount == 0) {
                predictionScores[0][i] = minEven;
                predictionScores[1][i] = -maxEven;
            } else if (evenCount == 0) {
                predictionScores[0][i] = -maxOdd;
                predictionScores[1][i] = minOdd;
            } else {
                predictionScores[0][i] = -maxOdd;
                predictionScores[1][i] = -maxEven;
            }
        }
    }

    static void solveProblem() {
        isSolved = false;
        dfs(0);
        if (!isSolved) {
            writer.println(-1);
        }
    }

    static void dfs(int currentRound) {
        if (isSolved) return;
        if (boxes <= 0) return;
        if (currentRound == rounds) {
            isSolved = true;
            for (int i = 0; i < rounds-1; i++) {
                String marbleType = (moveSequence[i] == 0) ? "Even" : "Odd";
                writer.print(marbleType + " ");
            }
            String marbleType = (moveSequence[rounds-1] == 0) ? "Even" : "Odd";
            writer.print(marbleType);
            writer.println();
            return;
        }
        for (int i = 0; i <= 1; i++) {
            boxes += predictionScores[i][currentRound];
            moveSequence[currentRound] = i;
            dfs(currentRound + 1);
            boxes -= predictionScores[i][currentRound];
        }
    }
}
