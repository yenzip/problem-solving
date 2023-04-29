class Solution {
    public int[] solution(int n) {

        int[][] triangle = new int[n][n];
        int N = n * (n + 1) / 2;
        int i = 0, j = 0, num = 1;
        while(num <= N) {
            while(i < n && triangle[i][j] == 0) {   // 아래로
                triangle[i++][j] = num++;
            }
            i--;    j++;
    
            while(j < n && triangle[i][j] == 0) {   // 오른쪽으로
                triangle[i][j++] = num++;
            }
            i--;    j -= 2;

            while(i > 0 && j > 0 && triangle[i][j] == 0) {  // 왼쪽 대각선 위로
                triangle[i--][j--] = num++;
            }
            i += 2;    j++;
        }

        int[] answer = new int[N];
        for(int x = 0, idx = 0; x < n; x++) {
            for(int y = 0; y <= x; y++) {
                answer[idx++] = triangle[x][y];
            }
        }

        return answer;
    }
}