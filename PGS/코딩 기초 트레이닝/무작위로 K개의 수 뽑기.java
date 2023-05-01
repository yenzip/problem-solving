import java.util.*;

class Solution {
    public int[] solution(int[] arr, int k) {
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < arr.length; i++) {
            if(list.size() == k) break;
            else if(!list.contains(arr[i])) list.add(arr[i]);
        }
        
        int[] answer = new int[k];
        Arrays.fill(answer, -1);
        for(int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}