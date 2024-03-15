// Source: https://usaco.guide/general/io

import java.io.*;
import java.util.*;

public class Problem1 {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		StringTokenizer st = new StringTokenizer(r.readLine());
		int n = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());
		boolean[] target = new boolean[n];
		int[] value = new int[n];
		int count = 0;
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(r.readLine());
			int a = Integer.parseInt(st.nextToken());
			value[i] = Integer.parseInt(st.nextToken());
			if(a == 1){
				target[i] = true;
				count++;
			}
		}
		

		HashSet<Integer> ans = new HashSet<Integer>();
		int pos = s - 1;
		int power = 1;
		boolean direction = true;
		int maxInterations = n;
		boolean bug = false;
		int oldvalue = -10000000;
		while ((pos >= 0 && pos < n) || power > n) {
			System.out.println(oldvalue + " " + value[pos]);
			if(value[pos] + oldvalue == 0){
				oldvalue = value[pos];
				pw.println(ans.size());
				pw.close();
				System.exit(0);
			}
			if (target[pos] && power >= value[pos] && !ans.contains(pos + 1)) {
				ans.add(pos + 1);
			}
			if (!target[pos]) {
				power += value[pos];
				if (direction) {
					direction = false;
				} else {
					direction = true;
				}
			}
			if (direction) {
				pos += power;
			} else {
				pos -= power;
			}
		}

		pw.println(ans.size());
		pw.close();
	}
}
