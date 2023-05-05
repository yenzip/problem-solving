class Solution {
    public int solution(int[][] lines) {

        int[] count = new int[201];
        for(int[] line : lines) {
            for(int i = line[0]; i < line[1]; i++) {
                count[i + 100]++;
            }
        }
        
        int answer = 0;
        for(int c : count) {
            if(c >= 2) answer++;
        }
        
        return answer;
    }
}