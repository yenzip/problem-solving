import java.util.*;

class Solution {
    int N, M;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    boolean isOut(int x, int y) {
        return (x < 0 || x >= N || y < 0 || y>= M);
    }
    
    int bfs(int maps[][]) {
        Queue<int[]> q = new LinkedList<>();
        int[][] dist = new int[N][M];
        
        dist[0][0] = 1;
        q.add(new int[]{0, 0});
        
        while(!q.isEmpty()) {
            int[] p = q.poll();
            int x = p[0];
            int y = p[1];
            
            if(x == N-1 && y == M-1) {
                return dist[N-1][M-1];
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(!isOut(nx, ny) && dist[nx][ny] == 0 && maps[nx][ny] == 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.add(new int[] {nx, ny});
                }
            }
        }
        
        return -1;
    }
    
    public int solution(int[][] maps) {
        N = maps.length;
        M = maps[0].length;
        
        int answer = bfs(maps);
        
        return answer;
    }
}