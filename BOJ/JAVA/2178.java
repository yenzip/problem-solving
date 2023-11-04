import java.util.*;

public class Main {
    
    static int N, M;
    static int[][] A;
    static int[][] level;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    public static boolean isOut(int x, int y) {
        return (x < 0 || x >= N || y < 0 || y >= M);
    }
    
    public static int bfs() {
        Queue<int[]> q = new LinkedList<>();
        
        q.add(new int[]{0, 0});
        level[0][0] = 1;
        
        while(!q.isEmpty()) {
            int[] p = q.poll();
            int x = p[0];
            int y = p[1];
            
            if(x == N-1 && y == M-1) {
                return level[x][y];
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(!isOut(nx, ny) && A[nx][ny] == 1 && level[nx][ny] == -1) {
                    q.add(new int[]{nx, ny});
                    level[nx][ny] = level[x][y] + 1;
                }
            }
        }
        
        return -1;
    }
    
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      
      N = sc.nextInt();
      M = sc.nextInt();
      
      A = new int[N][M];
      level = new int[N][M];
      
      for(int i = 0; i < N; i++) {
          String line = sc.next();
          for(int j = 0; j < M; j++) {
              A[i][j] = line.charAt(j) - '0';
              level[i][j] = -1;
          }
      }
      
      System.out.println(bfs());
    }
}