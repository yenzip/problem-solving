class Solution {
    boolean[] visited;
    
    void dfs(int[][] computers, int num) {
        visited[num] = true;
        
        for(int i = 0; i < computers.length; i++) {
            if(!visited[i] && computers[num][i] == 1) {
                dfs(computers, i);
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