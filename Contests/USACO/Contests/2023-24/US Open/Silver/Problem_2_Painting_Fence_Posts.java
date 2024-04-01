import java.util.*;

public class Problem_2_Painting_Fence_Posts {
    static class Fp implements Comparable<Fp>{
        int x;
        int y;
        public Fp(int x, int y){
            this.x = x;
            this.y = y;
        }
        @Override
        public int compareTo(Fp o) {
            if(x != o.x){
                return Integer.compare(x, o.x);
            }
            return Integer.compare(y, o.y);
        }

        
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Number of cows
        int P = scanner.nextInt(); // Number of fence posts

        // Initialize touch count for each fence post
        int[] touchCount = new int[P];

        // Read positions of fence posts
        Fp[] fencePosts = new Fp[P];
        for (int i = 0; i < P; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            fencePosts[i] = new Fp(x, y);
        }
        Arrays.sort(fencePosts);
        // Process each cow's walk
        for (int i = 0; i < N; i++) {
            int startX = scanner.nextInt();
            int startY = scanner.nextInt();
            int endX = scanner.nextInt();
            int endY = scanner.nextInt();

            // Perform flood fill to find touched fence posts
            Set<Integer> touchedPosts = floodFill(startX, startY, endX, endY, fencePosts);

            // Increment touch count for each touched post
            for (int post : touchedPosts) {
                touchCount[post]++;
            }
        }

        // Output touch count for each fence post
        for (int count : touchCount) {
            System.out.println(count);
        }
        scanner.close();
    }

    // Flood fill algorithm to find touched fence posts
    static Set<Integer> floodFill(int startX, int startY, int endX, int endY, Fp[] fencePosts) {
        Set<Integer> touched = new HashSet<>();
        int minX = Math.min(startX, endX);
        int maxX = Math.max(startX, endX);
        int minY = Math.min(startY, endY);
        int maxY = Math.max(startY, endY);

        for (int i = 0; i < fencePosts.length; i++) {
            int x = fencePosts[i].x;
            int y = fencePosts[i].y;

            if (x == startX && y >= minY && y <= maxY) {
                touched.add(i);
            } else if (y == startY && x >= minX && x <= maxX) {
                touched.add(i);
            } else if (x == endX && y >= minY && y <= maxY) {
                touched.add(i);
            } else if (y == endY && x >= minX && x <= maxX) {
                touched.add(i);
            }
        }

        return touched;
    }
}
