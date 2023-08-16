import java.util.*;

class Solution {
    int n, m;
    String[] key = {"up", "down", "left", "right"};
    int[] dx = {0, 0, -1, 1};
    int[] dy = {1, -1, 0, 0};
    
    boolean isOut(int x, int y) {
        return (x < -n || x > n || y < -m || y > m);
    }
    
    public int[] solution(String[] keyinput, int[] board) {
        n = (board[0] - 1) / 2;
        m = (board[1] - 1) / 2;
        
        int x = 0, y = 0;
        
        for(String keys : keyinput) {
            int idx = Arrays.asList(key).indexOf(keys);
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            
            if(isOut(nx, ny)) {
                continue;
            }
            
            x = nx;
            y = ny;
        }
        
        return new int[]{x, y};
    }
}