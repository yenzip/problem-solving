class Solution {
    static int[] answer;
    static char[][] arr;
    static boolean[][] visited;
    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};
    
    boolean isOut(int x, int y) {
        return (x < 0 || x >= 5 || y < 0 || y >= 5);
    }
    
    void dfs(int idx, int x, int y, int depth) {
        if(depth == 2) return;
        
        visited[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isOut(nx, ny) || visited[nx][ny] || arr[nx][ny] == 'X') continue;
            else if(arr[nx][ny] == 'P') {
                answer[idx] = 0;
                return;
            }
            else dfs(idx, nx, ny, depth + 1);
        }
    }
    
    public int[] solution(String[][] places) {
        answer = new int[5];
        
        for(int i = 0; i < 5; i++) {
            answer[i] = 1;
            arr = new char[5][5];
            
            for(int j = 0; j < 5; j++) {
                arr[j] = places[i][j].toCharArray();
            }
            
            for(int x = 0; x < 5; x++) {
                for(int y = 0; y < 5; y++) {
                    if(arr[x][y] == 'P') {
                        visited = new boolean[5][5];
                        dfs(i, x, y, 0);
                    }
                }
            }
        }
        return answer;
    }
}