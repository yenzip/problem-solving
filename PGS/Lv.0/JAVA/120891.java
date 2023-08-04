class Solution {
    public int solution(int order) {
        String s = Integer.toString(order);
        int answer = s.length() - s.replaceAll("[369]", "").length();    
        
        return answer;
    }
}