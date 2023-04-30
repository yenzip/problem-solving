class Solution {
    
    public int calc(int a, int b, String op) {
        int result = 0;
        if(op.equals("+")) {
            result = a + b;
        }
        else if(op.equals("-")) {
            result = a - b;
        }
        else if(op.equals("*")) {
            result = a * b;
        }
        return result;
    }
    
    public int solution(String binomial) {
        
        String[] arr = binomial.split(" ");
        int a = Integer.parseInt(arr[0]);
        int b = Integer.parseInt(arr[2]);
        
        int answer = calc(a, b, arr[1]);
        
        return answer;
    }
}