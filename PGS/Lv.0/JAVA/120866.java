class Solution {
    int n, m;
    int answer;
    int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    boolean isOut(int x, int y) {
        return (x < 0 || x >= n || y < 0 || y >= m);
    }
    
    public int solution(int[][] board) {
        n = board.length;
        m = board[0].length;
        answer = n * m;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 1) {
                    answer--;
                    for(int k = 0; k < 8; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        
                        if(!isOut(nx, ny) && board[nx][ny] == 0) {
                            board[nx][ny] = 2;
                            answer--;
                        }
                    }
                }
            }
        }
        
        return answer;
    }
}