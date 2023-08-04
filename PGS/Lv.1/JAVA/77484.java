class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int zero = 0;
        int match = 0;
        
        for(int l : lottos) {
            if(l == 0) {
                zero++;
            }
            else {
                for(int w : win_nums) {
                    if(l == w) {
                        match++;
                        break;
                    }
                }
            }
        }
        
        int hRank = Math.min(7 - match - zero, 6);
        int lRank = Math.min(7 - match, 6);
        
        return new int[]{hRank, lRank};
    }
}