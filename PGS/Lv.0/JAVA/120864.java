class Solution {
    public int solution(String my_string) {
        int answer = 0;
        String[] num = my_string.split("[a-zA-z]");
        
        for(int i = 0; i < num.length; i++) {
            if(!num[i].isEmpty()) {
                answer += Integer.parseInt(num[i]);
            }
        }
        
        return answer;
    }
}