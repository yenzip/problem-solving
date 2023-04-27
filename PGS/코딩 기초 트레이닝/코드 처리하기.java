class Solution {
    public String solution(String code) {
        String answer = "";
        
        int mode =  0;
        for(int i = 0; i < code.length(); i++) {
            char c = code.charAt(i);
            if(mode == 0) {
                if(c == '1') {
                    mode = 1;
                }
                else if(i % 2 == 0) {
                    answer += c;
                }
            }
            else {
                if(c == '1') {
                    mode = 0;
                }
                else if(i % 2 == 1) {
                    answer += c;
                }
            }
        }
        
        if(answer.length() == 0) {
            answer = "EMPTY";
        }
        
        return answer;
    }
}