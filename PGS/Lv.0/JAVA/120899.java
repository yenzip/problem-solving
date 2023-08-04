class Solution {
    public int[] solution(int[] array) {
        int maxIdx = 0;
        int maxVal = 0;
        
        for(int i = 0; i < array.length; i++) {
            if(maxVal < array[i]) {
                maxIdx = i;
                maxVal = array[i];
            }
        }
         
        return new int[] {maxVal, maxIdx};
    }
}