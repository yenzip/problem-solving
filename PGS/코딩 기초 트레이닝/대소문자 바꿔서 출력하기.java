import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String answer = "";
        for(int i = 0; i < a.length(); i++) {
            char c = a.charAt(i);
            if(c >= 65 && c <= 90) {
                answer += a.valueOf(c).toLowerCase();
            }
            else {
                answer += a.valueOf(c).toUpperCase();
            }
        }
        System.out.println(answer);
    }
}