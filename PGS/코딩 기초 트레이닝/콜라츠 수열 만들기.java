import java.util.*;

class Solution {
    public int[] solution(int n) {
        int[] answer;
        
        List<Integer> list = new ArrayList<>();
        while(true) {
            list.add(n);
            
            if(n == 1) {
                break;
            }
            
            if(n % 2 == 0) {
                n /= 2;
            }
            else {
                n = 3 * n + 1;
            }
        }
        
        answer = list.stream().mapToInt(i->i).toArray();
        
        return answer;
    }
}