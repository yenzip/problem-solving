import java.util.*;

class Solution {
    public static class Point {
        int x;
        int y;
        
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    static int n, m;
    static int[][] dist;
    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};
    
    boolean isOut(int x, int y) {
        return (x < 0 || x >= n || y < 0 || y >= m);
    }
    
    void bfs(int[][] maps, int sx, int sy) {
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(sx, sy));
        dist[sx][sy] = 1;
        
        while(!q.isEmpty()) {
            Point p = q.poll();
            int x = p.x;
            int y = p.y;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(!isOut(nx, ny) && maps[nx][ny] == 1 && dist[nx][ny] == 0) {
                    q.add(new Point(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        } 
    }

    public int solution(int[][] maps) {
        n = maps.length;
        m = maps[0].length;
        dist = new int[n][m];
        
        bfs(maps, 0, 0);
        
        return dist[n-1][m-1] == 0 ? -1 : dist[n-1][m-1];
    }
}