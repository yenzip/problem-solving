class Solution {
    public String solution(String[] my_strings, int[][] parts) {
        String answer = "";
        
        for(int i = 0; i < parts.length; i++) {
            int s = parts[i][0], e = parts[i][1];
            answer += my_strings[i].substring(s, e + 1);
        }
        
        return answer;
    }
}