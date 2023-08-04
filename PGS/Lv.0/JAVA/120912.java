class Solution {
    public int solution(int[] array) {
        int answer = 0;
        
        for(int a : array) {
            String s = Integer.toString(a);
            answer += s.length() - s.replaceAll("7", "").length();
        }
        
        return answer;
    }
}