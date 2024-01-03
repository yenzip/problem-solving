import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int R = Integer.parseInt(input[0]);
        int C = Integer.parseInt(input[1]);

        String[] arr = new String[R];
        for (int i = 0; i < R; ++i) {
            arr[i] = br.readLine();
        }

        Set<String> st = new HashSet<>();
        for (int j = 0; j < C; ++j) {
            String s = "";
            for (int i = 0; i < R; ++i) {
                s += arr[i].charAt(j);
            }
            st.add(s);
        }

        int answer = 0;
        int row = 0;
        while (row < R - 1) {
            Set<String> tmp = new HashSet<>();
            for (String s : st) {
                tmp.add(s.substring(1));
            }
            st = tmp;

            if (st.size() != C) {
                break;
            }

            answer++;
            row++;
        }

        System.out.println(answer);
    }
}