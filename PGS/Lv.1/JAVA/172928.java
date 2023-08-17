import java.util.*;

class Solution {
    int n, m;
    char[][] arr;
    String[] dir = {"N", "S", "W", "E"};
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    boolean isOut(int x, int y) {
        return (x < 0|| x >= n || y < 0 || y >= m);
    }
    
    boolean check(int x, int y, int idx, int move) {
        for(int i = 1; i <= move; i++) {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            
            if(isOut(nx, ny) || arr[nx][ny] == 'X') {
                return false;
            }
            
            x = nx;
            y = ny;
        }
        
        return true;
    } 
    
    
    public int[] solution(String[] park, String[] routes) {
        int[] answer = {0, 0};
        int x, y;
        
        n = park.length;
        m = park[0].length();
        arr = new char[n][m];
        
        for(int i = 0;  i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i][j] = park[i].charAt(j);
                if(arr[i][j] == 'S') {
                    answer[0] = i;
                    answer[1] = j;
                }
            }
        }
        
        for(String route : routes) {
            String[] sp = route.split(" ");
            int idx = Arrays.asList(dir).indexOf(sp[0]);
            int move = Integer.parseInt(sp[1]);
            
            if(check(answer[0], answer[1], idx, move)) {
                answer[0] += dx[idx] * move;
                answer[1] += dy[idx] * move;
            }
        }
        
        return answer;
    }
}