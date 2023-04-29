import java.util.*;

class Solution {
    public static class Point { // 점
        public final long x, y;
        private Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }
    
    private Point intersection(long A, long B, long C, long D, long E, long F) {   // 두 직선의 정수 교점 찾아 반환
        double x = (double) (B * F - E * D) / (A * D - B * C);
        double y = (double) (E * C - A * F) / (A * D - B * C);
        return x % 1 == 0 && y % 1 == 0 ? new Point((long) x, (long) y) : null; // 정수인지 확인
    }
    
    private Point minimumPoint(List<Point> points) { // x, y의 최소값
        long x = Long.MAX_VALUE;
        long y = Long.MAX_VALUE;
        
        for(Point p : points) {
            x = Math.min(x, p.x);
            y = Math.min(y, p.y);
        }
        
        return new Point(x, y);
    }
    
    private Point maximumPoint(List<Point> points) { // x, y의 최댓값
        long x = Long.MIN_VALUE;
        long y = Long.MIN_VALUE;
        
        for(Point p : points) {
            x = Math.max(x, p.x);
            y = Math.max(y, p.y);
        }
        
        return new Point(x, y);
    }
    
    public String[] solution(int[][] line) {
        
        List<Point> points = new ArrayList<>(); // 정수 교점 저장
        for(int i = 0; i < line.length; i++) {
            for(int j = i + 1; j < line.length; j++) {
                Point p = intersection(line[i][0], line[i][1], line[j][0], line[j][1], line[i][2], line[j][2]);
                if(p != null) {
                    points.add(p);
                }
            }
        }
        
        Point minimum = minimumPoint(points);   // 좌표의 최소/최댓값으로 범위 구하기
        Point maximum = maximumPoint(points);   
        
        int width = (int) (maximum.x - minimum.x + 1); // 세로
        int height = (int) (maximum.y - minimum.y + 1);  // 가로
        
        char[][] arr = new char[height][width];
        for(char[] row : arr) {
            Arrays.fill(row, '.');  // '.'으로 채우기
        }
        
        for(Point p : points) { // 교점 '*' 표시
            int row = (int) (maximum.y - p.y);
            int col = (int) (p.x - minimum.x);
            arr[row][col] = '*';
        }
        
        String[] answer = new String[arr.length];   // char 배열 -> String
        for(int i =0; i < answer.length; i++) {
            answer[i] = new String(arr[i]);
        }
        
        return answer;
    }
}