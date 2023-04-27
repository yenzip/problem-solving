class Solution {
    public String solution(String my_string, String overwrite_string, int s) {
        String answer = my_string.substring(0, s);
        int e = overwrite_string.length();
        answer += overwrite_string;
        answer += my_string.substring(s + e);
        
        return answer;
    }
}