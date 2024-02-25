
import java.io.*;
import java.util.*;

public class ConventionII {
    public static void main(String[] args) throws IOException {
        // Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        // PrintWriter pw = new PrintWriter(System.out);
        Scanner in = new Scanner(new BufferedReader(new FileReader("convention2.in")));
        PrintWriter pw = new PrintWriter("convention2.out");
        int n = in.nextInt();
        Cow[] cows = new Cow[n];
        for (int i = 0; i < n; i++) {
            int arrivalTime = in.nextInt();
            int timeSpent = in.nextInt();
            cows[i] = new Cow(arrivalTime, timeSpent, i);
        }
        Arrays.sort(cows, Comparator.comparingInt(cow -> cow.arrival));
        int maxWaitTime = 0;
        //int currentWaitTime = 0;
        int curr = 0;
        int time = 0;
        PriorityQueue<Cow> waiting = new PriorityQueue<>();
        while (curr < n || !waiting.isEmpty()) {
			// this cow can be processed
			if (curr < n && cows[curr].arrival <= time) {
				waiting.add(cows[curr]);
				curr++;
				// no cow waiting, skip to the next cow.
			} else if (waiting.size() == 0) {
				// set time to the ending time of the next cow.
				time = cows[curr].arrival + cows[curr].spent;
				curr++;
			} else {
				// process the next cow
				Cow next = waiting.peek();
				maxWaitTime = Math.max(maxWaitTime, time - next.arrival);

				// set the time to when this cow finishes
				time += next.spent;
				waiting.poll();
			}
		}
        pw.println(maxWaitTime);
        pw.close();
        in.close();
    }
    static class Cow implements Comparable<Cow> {//idk why we implement this, probobly so we can use it
        int arrival;
        int spent;
        int seniority;
        public Cow(int arrival, int spent, int seniority){
            this.arrival = arrival;
            this.spent = spent;
            this.seniority = seniority;
        }

        @Override //to override the original method
        public int compareTo(Cow other) {
			return seniority - other.seniority; //this returns either a value greater, less than, or equal to zero.
		}
    }
}
