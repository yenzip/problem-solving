import java.util.*;

class Solution {
    public int[] solution(int[] num_list) {
        int[] answer = new int[num_list.length - 5];
        
        Arrays.sort(num_list);
        for(int i = 5, idx = 0; i < num_list.length; i++, idx++) {
            answer[idx] = num_list[i];
        }
        
        return answer;
    }
}