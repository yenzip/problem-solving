import java.util.*;

class Solution {
    public String[] solution(String myString) {
        
        List<String> list = new ArrayList<>();
        int s = 0;
        for(int i = 0; i < myString.length(); i++) {
            if(myString.charAt(i) == 'x') {
                if(s != i) list.add(myString.substring(s, i));
                s = i + 1;
            }
        }
        if(s < myString.length()) list.add(myString.substring(s, myString.length()));
        
        String[] answer = list.toArray(String[]::new);
        Arrays.sort(answer, (v1, v2) -> v1.compareTo(v2));
        
        return answer;
    }
}