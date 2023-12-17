class Solution {

    static class Point implements Comparable<Point> {
        int[] point;
        double distance;

        Point(int[] point, double distance) {
            this.point = point;
            this.distance = distance;
        }

        @Override
        public int compareTo(Point target) {
            return this.distance < target.distance ? -1 : 1;
        }
    }

    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Point> pq = new PriorityQueue<>();
        int[][] answer = new int[k][];

        for(int[] point : points) {
            double distance = Math.pow(point[0], 2) + Math.pow(point[1], 2);
            pq.offer(new Point(point, distance));
        }

        for(int i = 0; i < k; i++) {
            answer[i] = pq.poll().point;
        }

        return answer;
    }
}