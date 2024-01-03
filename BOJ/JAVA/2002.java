import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int N = Integer.parseInt(br.readLine());
      
      Queue<String> in = new LinkedList<>();
      for(int i = 0; i < N; i++) {
          in.add(br.readLine());
      }
      
      Queue<String> out = new LinkedList<>(); 
      for(int i = 0; i < N; i++) {
          out.add(br.readLine());
      }
      
      int answer = 0;
      while(!out.isEmpty()) {
          String outCar = out.poll();
          
          if(!in.peek().equals(outCar)) {
              answer++;
              in.remove(outCar);
          } else {
              in.poll();
          }
      }
      
      System.out.println(answer);
      br.close();
    }
}