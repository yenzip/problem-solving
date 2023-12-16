import java.util.*;

public class Main {
    static class Balloon {
        int num;
        int move;

        public Balloon(int num, int move) {
            this.num = num;
            this.move = move;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Deque<Balloon> dq = new ArrayDeque<>();
        StringBuilder answer = new StringBuilder();

        int N = sc.nextInt();

        for (int i = 1; i <= N; i++) {
            dq.add(new Balloon(i, sc.nextInt()));
        }

        while (!dq.isEmpty()) {
            Balloon b = dq.pollFirst();
            answer.append(b.num).append(" ");
            
            if(dq.isEmpty()) {
                break;
            }

            if (b.move > 0) {
                for (int i = 1; i < b.move; i++) {
                    dq.addLast(dq.pollFirst());
                }
            } else {
                for (int i = 0; i < Math.abs(b.move); i++) {
                    dq.addFirst(dq.pollLast());
                }
            }
        }

        System.out.println(answer.toString());
    }
}