import java.util.*;

class Solution {
    public void check(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] >= 50 && arr[i] % 2 == 0) {
                arr[i] /= 2;
            }
            else if(arr[i]< 50 && arr[i] % 2 == 1) {
                arr[i] = arr[i] * 2 + 1;
            }
        }
    }
    
    public int solution(int[] arr) {
        int x = 0;
        
        while(true) {
            int[] arr2 = arr.clone();
            check(arr2);
            
            if(Arrays.equals(arr, arr2)) {
                break;
            }
            
            arr = arr2.clone();

            x++;
        }
        
        return x;
    }
}