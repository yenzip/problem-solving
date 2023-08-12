import java.util.*;

class Solution {
    static String[] vowel = {"A", "E", "I", "O", "U"};
    static List<String> list = new ArrayList<>();

    static void search(String word, String now) {        
        for(String s : vowel) {
            if(now.length() < 5) {
                list.add(now + s);
                search(word, now + s);
            }
        }
    }

    public int solution(String word) {
        int answer = 0;

        search(word, "");

        for(int i = 0; i < list.size(); i++) {
            if(word.equals(list.get(i))) {
                answer = i + 1;
                break;
            }
        }

        return answer;
    }
}