
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeSet;
public class Moorbius {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int f = in.nextInt();
        in.nextLine();
        StringBuilder s2 = new StringBuilder(in.nextLine());
        // System.out.println(n + " " + f);
        // System.out.println(s);

        ArrayList<String> l = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        TreeSet<String> ans = new TreeSet<>();

        for (int i = 3; i <= n; i++) {
            l.add(s2.substring(i - 3, i));
        }
        // System.out.println(l);
        for (int i = 0; i < l.size(); i++) {
            if (!isMoo(l.get(i))) {
                continue;
            }
            if (!map.containsKey(l.get(i))) {
                map.put(l.get(i), 1);
                // i += 3; the next one can't be a moo, and the one after can only be a different type of moo
            } else {
                map.put(l.get(i), map.get(l.get(i)) + 1);
            }
        }

        for (String key : map.keySet()) {
            if (map.get(key) >= f) {
                ans.add(key);
            }
        }
        //System.out.println(map);
        char[] letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        for(int a = 0; a < s2.length(); a++){
            StringBuilder s = new StringBuilder(s2.toString());
            for(int a2 = 0; a2 < 26; a2++){
                if(s.charAt(a) == letters[a2])continue;
                s.setCharAt(a, letters[a2]);

                for (int i = Math.max(0, a - 2); i <= Math.min(n - 3, a); i++) {
                    String sub = s.substring(i, i + 3);
                    if (isMoo(sub)) {
                        int current = map.getOrDefault(sub, 0);
                        // if(current == 1)System.out.println(sub);
                        for (int z = Math.max(0, a - 2); z <= Math.min(n - 3, a); z++) {
                            if(s2.substring(z, z + 3).equals(sub))current--;
                            // if(current==1)System.out.println("!");
                        }
                        //if(a == 0)
                        // System.out.println(sub);
                        int count = current;
                        for (int z = Math.max(0, a - 2); z <= Math.min(n - 3, a); z++) {
                            if(s.substring(z, z + 3).equals(sub))count++;
                        }
                        // System.out.println(count);
                        if (count >= f) {
                            ans.add(sub);
                        }
                    }
                }

                // int q = 0;
                // for (int i = 0; i < l.size(); i++) {
                //     if (!map.containsKey(l.get(i))) {
                //         continue;
                //     }
                //     if (map.get(l.get(i)) >= f) {
                //         q++;
                //     }
                // }
                // for (String key : map.keySet()) {
                //     if (map.get(key) >= f) {
                //         q++;
                //     }
                // }
                // System.out.println(q);
                // for (int i = 0; i < l.size(); i++) {
                //     if (!map.containsKey(l.get(i))) {
                //         continue;
                //     }
                //     if (map.get(l.get(i)) >= f) {
                //         System.out.println(l.get(i));
                //     }
                // }
            }
        }
        System.out.println(ans.size());
        for(String s : ans) {
            System.out.println(s);
        }
        in.close();
    }

    public static boolean isMoo(String s) {
        return s.charAt(0) != s.charAt(1) && s.charAt(1) == s.charAt(2);
    }
}