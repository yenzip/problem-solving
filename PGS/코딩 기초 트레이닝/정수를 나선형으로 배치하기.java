class Solution {
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        
        int i = 0, j = 0, num = 1;
        while(num <= n * n) {
            while(j < n && answer[i][j] == 0) {
                answer[i][j++] = num++;
            }
            i++;    j--;
            
            while(i < n && answer[i][j] == 0) {
                answer[i++][j] = num++;
            }
            i--;    j--;
            
            while(j >= 0 && answer[i][j] == 0) {
                answer[i][j--] = num++;
            }
            i--;    j++;
            
            while(i >= 0 && answer[i][j] == 0) {
                answer[i--][j] = num++;
            }
            i++;    j++;
        }
        
        return answer;
    }
}