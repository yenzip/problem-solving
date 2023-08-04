import java.util.*;

class Solution {
    static int[] p1 = {1, 2, 3, 4, 5};
    static int[] p2 = {2, 1, 2, 3, 2, 4, 2, 5};
    static int[] p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    static int[] score = {0, 0, 0, 0};
    
    public int[] solution(int[] answers) {
        int size1 = p1.length;
        int size2 = p2.length;
        int size3 = p3.length;
        
        for(int i = 0; i < answers.length; i++) {
            if(answers[i] == p1[i%size1]) {
                score[1]++;
            }
            if(answers[i] == p2[i%size2]) {
                score[2]++;
            }
            if(answers[i] == p3[i%size3]) {
                score[3]++;
            }
        }
        
        int maxVal = Math.max(score[1], Math.max(score[2], score[3]));
        List<Integer> answer = new ArrayList<>();
        
        for(int i= 1; i <= 3; i++) {
            if(score[i] == maxVal) {
                answer.add(i);
            }
        }
          
        return answer.stream().mapToInt(i->i).toArray();
    }
}