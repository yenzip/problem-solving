import java.util.*;

class Solution {
    public int solution(int[] nums) {
        Set<Integer> hs = new HashSet<>();
        int size = nums.length / 2;
        
        for(int num : nums) {
            hs.add(num);
        }
        
        if (hs.size() <= size) {
            return hs.size();
        }
        
        return size;
    }
}