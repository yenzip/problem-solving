class Solution {
    
    static int n, answer;
    
    void dfs(int[] numbers, int target, int num, int depth) {
        if(depth == n) {
            if(num == target) answer++;
            return;
        }
        
        dfs(numbers, target, num + numbers[depth], depth + 1);
        dfs(numbers, target, num - numbers[depth], depth + 1);
    }
    
    public int solution(int[] numbers, int target) {
        answer = 0;
        n = numbers.length;
        
        dfs(numbers, target, 0, 0);
        
        return answer;
    }
}