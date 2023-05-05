class Solution {
    
    static boolean[] visited;
    
    void dfs(int[][] computers, int now) {
        visited[now] = true;
        
        for(int next = 0; next < computers.length; next++) {
            if(computers[now][next] == 1 && !visited[next]) {
                dfs(computers, next);
            }   
        }
    }
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        
        visited = new boolean[n];
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(computers, i);
                answer++;
            }
        }
        
        return answer;
    }
}