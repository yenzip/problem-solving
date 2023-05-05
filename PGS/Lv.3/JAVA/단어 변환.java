import java.util.*;

class Solution {
    public static class Word {
        String word;
        int dist;
        public Word(String word, int dist) {
            this.word = word;
            this.dist = dist;
        }
    }
    
    static boolean[] visited;
    
    boolean diff(String now, String next) {
        int count = 0;
        for(int i = 0; i < now.length(); i++) {
            if(now.charAt(i) != next.charAt(i)) count++;
        }
        return count == 1;
    }
    
    int bfs(String[] words, String target, String begin) {
        Queue<Word> q = new LinkedList<>();
        q.add(new Word(begin, 0));
        
        while(!q.isEmpty()) {
            Word w = q.poll();
            String now = w.word;
            int dist = w.dist;
            
            if(now.equals(target)) {
                return dist;
            }
            
            for(int next = 0; next < words.length; next++) {
                if(!visited[next] && diff(now, words[next])) {
                    q.add(new Word(words[next], dist + 1));
                    visited[next] = true;
                }
            }
        }
        
        return 0;
    }
    
    public int solution(String begin, String target, String[] words) {
        visited = new boolean[words.length];
        int answer = bfs(words, target, begin);
        return answer;
    }
}