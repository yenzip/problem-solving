import java.util.*;

class Solution {
    public int solution(int n) {
        boolean[] isPrime = new boolean[n + 1];
        int answer = 0;
        
        Arrays.fill(isPrime, true);
        
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i = 2; i * i <= n; i++) {
            if(!isPrime[i]) {
                continue;
            }
            for(int j = i * 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
        
        for(int i = 1; i <= n; i++) {
            if(isPrime[i]) {
                answer++;
            }
        }
        
        return answer;
    }
}