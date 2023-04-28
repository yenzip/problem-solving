import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        
        int first;
        for(first = 0; first < arr.length; first++) {
            if(arr[first] == 2) {
                break;
            }
        }
        
        if(first == arr.length) {
            return new int[] {-1};
        }
        
        int last;
        for(last = arr.length -1; last >= 0; last--) {
            if(arr[last] == 2) {
                break;
            }
        }
        
        return Arrays.copyOfRange(arr, first, last + 1);
    }
}