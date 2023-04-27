import java.util.*;

class Solution {
    public int[] solution(int[] num_list) {
        int[] answer;
        
        int a = num_list[num_list.length -1];
        int b = num_list[num_list.length -2];
        
        List<Integer> list = new ArrayList<Integer>();
        for(int n : num_list) {
            list.add(n);
        }
        list.add(a > b ? a - b : a * 2);
        
        answer = list.stream().mapToInt(i -> i).toArray();
        
        return answer;
    }
}