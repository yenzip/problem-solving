import java.util.*;

class Solution {
    public String[] solution(String myStr) {
        String[] splitStr = myStr.split("a|b|c");
        List<String> list = new ArrayList<>();
        for(String s : splitStr) {
            if(!s.equals("")) list.add(s);
        }
        return list.size() == 0 ? new String[]{"EMPTY"} : list.toArray(String[]::new);
    }
}