class Solution {
    
    static final int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static final int[] dy = { -1, 0, 1, -1, 1, -1, 0, 1};
    static int n;
    static int[][] unsafe;
    
    boolean isOut(int x, int  y) {
        return (x < 0 || x >= n || y < 0 || y >= n);
    }
    
    void check(int[][] board, int x, int y) {
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!isOut(nx, ny) && board[nx][ny] == 0) {
                unsafe[nx][ny] = 1;
            }
        }
    }
    
    public int solution(int[][] board) {
        
        n = board.length;
        unsafe = new int[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                unsafe[i][j] = board[i][j];
            }
        }
 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1) {
                    check(board, i, j);
                }
            }
        }
        
        int answer = n * n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(unsafe[i][j] == 1) {
                    answer--;
                }
            }
        }
   
        return answer;
    }
}