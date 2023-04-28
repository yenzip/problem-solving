import java.util.*;

class Solution {
    public String solution(String my_string, int[] indices) {
        String answer = "";
        
        Arrays.sort(indices);
        int s = 0;
        for(int ind : indices) {
            answer += my_string.substring(s, ind);
            s = ind + 1;
        }
        answer += my_string.substring(s);
        
        return answer;
    }
}