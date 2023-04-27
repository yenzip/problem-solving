class Solution {
    public String solution(String my_string, int[][] queries) {

        for(int[] query : queries) {
            int s = query[0], e = query[1];
            char[] tmp = my_string.toCharArray();
            for(int i = s, j = e; i <= e; i++, j--) {
                tmp[j] = my_string.charAt(i);
            }
            my_string = String.valueOf(tmp);
        }
        
        
        return my_string;
    }
}