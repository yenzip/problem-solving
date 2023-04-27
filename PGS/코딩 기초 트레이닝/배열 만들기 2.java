import java.util.*;

class Solution {
    public int[] solution(int l, int r) {
        int[] answer;
        
        List<Integer> list = new ArrayList<>();
        for(int i = l; i <= r; i++) {
            boolean zero_five = true;
            int tmp = i;
            while(tmp > 0) {
                if(tmp % 10 != 0 && tmp % 10 != 5) {
                    zero_five = false;
                    break;
                }
                tmp /= 10;
            }
            if(zero_five) {
                list.add(i);
            }
        }
        
        if(list.isEmpty()) {
            list.add(-1);
        }
        
        answer = list.stream().mapToInt(i->i).toArray();
        
        return answer;
    }
}