class Solution {
    public int[][] solution(int[] num_list, int n) {
        int size = num_list.length / n;
        int[][] answer = new int[size][n];
        
        for(int i = 0, idx = 0; i < size; i++) {
            for(int j = 0; j < n; j++) {
                answer[i][j] = num_list[idx++];
            }
        }
        
        return answer;
    }
}