class Solution {
    public String solution(String X, String Y) {
        StringBuilder sb = new StringBuilder();
        int[] x = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int[] y = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        
        for(int i = 0; i < X.length(); i++) {
            x[X.charAt(i) - '0']++;
        }
        
        for(int i = 0; i < Y.length(); i++) {
            y[Y.charAt(i) - '0']++;
        }
        
        for(int i = 9; i >= 0; i--) {
            for(int j = 0; j < Math.min(x[i], y[i]); j++) {
                sb.append(String.valueOf(i));
            }
        }
        
        String answer = sb.toString();
        
        if(answer.length() == 0) {
            answer = "-1";
        }
        else if(answer.charAt(0) == '0') {
            answer = "0";
        }
        
        return answer;
    }
}