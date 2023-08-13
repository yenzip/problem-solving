import java.util.*;

class Solution {
    public int[] solution(int[] numbers, String direction) {
        int[] answer = new int[numbers.length];
        Deque<Integer> dq = new ArrayDeque<>();
        
        for(int i = 0; i < numbers.length; i++) {
            dq.add(numbers[i]);
        }
        
        if(direction.equals("right")) {
            dq.addFirst(dq.getLast());
            dq.removeLast();
        }
        else {
            dq.addLast(dq.getFirst());
            dq.removeFirst();
        }
        
        int idx = 0;
        Iterator<Integer> it = dq.iterator();
        
        while(it.hasNext()) {
            int n = it.next();
            answer[idx++] = n;
        }
        
        return answer;
    }
}