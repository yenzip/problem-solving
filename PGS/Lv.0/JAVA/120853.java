import java.util.*;

class Solution {
    public int solution(String s) {
        String[] sp = s.split(" ");
        Stack<Integer> stk = new Stack<>();
        
        for(int i = 0; i < sp.length; i++) {
            if(sp[i].equals("Z")) {
                if(!stk.empty()) {
                    stk.pop();
                }
            }
            else {
                stk.push(Integer.parseInt(sp[i]));
            }
        }
        
        int answer = 0;
        
        while(!stk.empty()) {
            answer += stk.pop();
        }

        return answer;
    }
}