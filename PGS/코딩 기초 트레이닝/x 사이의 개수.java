import java.util.*;

class Solution {
    public int[] solution(String myString) {
        
        char[] arr = myString.toCharArray();
        List<Integer> list = new ArrayList<>();
        int size = 0;
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] == 'x') {
                list.add(size);
                size = 0;
            }
            else {
                size++;
            }
        }
        list.add(size);
        
        int[] answer = list.stream().mapToInt(i->i).toArray();
        return answer;
    }
}