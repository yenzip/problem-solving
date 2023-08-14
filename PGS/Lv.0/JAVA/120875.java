import java.util.*;

class Solution {
    public int solution(int[][] dots) {
        
        Arrays.sort(dots, (o1, o2) -> {
            return o1[0] - o2[0];
        });
            
        int x1 = dots[1][0] - dots[0][0];
        int y1 = dots[1][1] - dots[0][1];
        int x2 = dots[3][0] - dots[2][0];
        int y2 = dots[3][1] - dots[2][1];
        
        return x1 * y2 == x2 * y1 ? 1 : 0;
    }
}