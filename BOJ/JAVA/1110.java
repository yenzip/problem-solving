import java.util.*;

public class Main {
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      int N = sc.nextInt();
      int x = N;
      int answer = 0;
      
      while(true) {
          int x1 = x / 10;
          int x2 = x % 10;
          
          if(x < 10) {
              x = x2 * 10 + x2;
          }
          else {
              int sum = x1 + x2;
              x = x2 * 10 + sum % 10;
          }
          
          answer++;
          
          if(x == N) {
              break;
          }
      }
      
      System.out.println(answer);
      
    }
}