class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        
        for(String b : babbling) {
            boolean possible = true;
            while(!b.isEmpty()) {
                if(b.startsWith("aya") || b.startsWith("woo")) {
                    b = b.substring(3);
                }
                else if(b.startsWith("ye") || b.startsWith("ma")) {
                    b = b.substring(2);
                }
                else {
                    possible = false;
                    break;
                }
            }
            if(possible) answer++;
        }
        
        return answer;
    }
}