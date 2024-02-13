
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class CoolInput {
	public static void main(String[] args) throws IOException {
		BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
		read.readLine();
		int[] arr = Arrays.stream(read.readLine().split(" "))
                  .mapToInt(Integer::parseInt)
                  .toArray();

        System.out.println(Arrays.toString(arr));

		long maxSubSum = arr[0];
		long runningPrefSum = 0;
		long minPrefSum = 0;
		for (int i : arr) {
			runningPrefSum += i;
			maxSubSum = Math.max(maxSubSum, runningPrefSum - minPrefSum);
			minPrefSum = Math.min(minPrefSum, runningPrefSum);
		}
		System.out.println(maxSubSum);
	}
}