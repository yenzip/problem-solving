import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> list = new ArrayList<>();
        
        list.add(arr[0]);
        
        for(int i = 1; i < arr.length; i++) {
            if(arr[i - 1] == arr[i]) {
                continue;
            }
            else {
                list.add(arr[i]);
            }
        }
        
        int[] answer = list.stream().mapToInt(i-> i).toArray();

        return answer;
    }
}