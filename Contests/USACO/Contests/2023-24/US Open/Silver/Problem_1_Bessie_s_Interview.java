// import java.util.*;

// public class Problem_1_Bessie_s_Interview {
//     public static void main(String[] args) {
//         Scanner inputScanner = new Scanner(System.in);
//         int numFarmers = inputScanner.nextInt();
//         int numIntervals = inputScanner.nextInt();
        
//         int[] intervals = new int[numFarmers];
//         for (int i = 0; i < numFarmers; i++) {
//             intervals[i] = inputScanner.nextInt();
//         }
        
        
//         int currentInterval = numIntervals;
//         int currentTime = 0;
//         PriorityQueue<int[]> priorityQueue = new PriorityQueue<>(numIntervals, (a, b) -> Integer.compare(a[1], b[1]));
        
//         for (int i = 0; i < numIntervals; i++) {
//             priorityQueue.add(new int[]{i, intervals[i]});
//         }
        
//         int z = -1;
//         int t = -1;
//         while (z == -1) {
//             int nextTime = priorityQueue.peek()[1];
//             ArrayList<int[]> nextTwo = new ArrayList<>();
            
//             while (priorityQueue.peek()[1] == nextTime) {
//                 nextTwo.add(priorityQueue.poll());
//             }
            
//             int a = nextTwo.get(0)[0];
            
//             for (int i = 1; i < nextTwo.size(); i++) {
//                 int iFarmer = nextTwo.get(i)[0];
//                 connectionMap.get(a).add(iFarmer);
//                 connectionMap.get(iFarmer).add(a);
//             }
            
//             for (int i = 0; i < nextTwo.size(); i++) {
//                 if (currentInterval == numFarmers) {
//                     z = nextTwo.get(i)[0];
//                     t = nextTime;
//                 } else {
//                     priorityQueue.add(new int[]{nextTwo.get(i)[0], nextTime + intervals[currentInterval]});
//                     currentInterval++;
//                 }
//             }
//         }
        
//         HashSet<Integer> finalSet = new HashSet<>();
//         Stack<Integer> toVisitStack = new Stack<>();
//         toVisitStack.add(z);
        
//         while (!toVisitStack.isEmpty()) {
//             int current = toVisitStack.pop();
//             finalSet.add(current);
            
//             for (int next : connectionMap.get(current)) {
//                 if (!finalSet.contains(next)) {
//                     toVisitStack.add(next);
//                 }
//             }
//         }
        
//         System.out.println(t);
//         StringBuilder resultBuilder = new StringBuilder();
        
//         for (int i = 0; i < numIntervals; i++) {
//             if (finalSet.contains(i)) {
//                 resultBuilder.append(1);
//             } else {
//                 resultBuilder.append(0);
//             }
//         }
        
//         System.out.println(resultBuilder.toString());
//     }
// }
