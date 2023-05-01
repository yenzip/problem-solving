class Solution {
    public int solution(String[] strArr) {

        int[] len = new int[31];
        for(String str : strArr) {
            len[str.length()]++;
        }
        
        int answer = 0;
        for(int i = 1; i <= 30; i++) {
            answer = Math.max(answer, len[i]);
        }
        
        return answer;
    }
}