import java.util.*;

class Solution {
    public int solution(String before, String after) {
        String[] b = before.split("");
        String[] a = after.split("");
        
        Arrays.sort(b);
        Arrays.sort(a);
        
        for(int i = 0; i < a.length; i++) {
            if(!b[i].equals(a[i])) {
                return 0;
            }
        }
        
        return 1;
    }
}