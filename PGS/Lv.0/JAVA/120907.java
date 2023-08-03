class Solution {
    public String[] solution(String[] quiz) {
        String[] answer = new String[quiz.length];
        
        for(int i = 0; i < quiz.length; i++) {
            String[] s = quiz[i].split(" ");
            
            int x = Integer.parseInt(s[0]);
            int y = Integer.parseInt(s[2]);
            int z = Integer.parseInt(s[4]);
            
            if(s[1].equals("+")) {
                if(x + y == z) {
                    answer[i] = "O";
                }
                else {
                    answer[i] = "X";
                }
            }
            else {
                if(x - y == z) {
                    answer[i] = "O";
                }
                else {
                    answer[i] = "X";
                }
            }
        }
        
        return answer;
    }
}