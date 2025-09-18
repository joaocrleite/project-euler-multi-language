
public class p002 {
  public static void main(String[] args) {
   
    int result = resolve(4000000);

    System.out.printf("Result=%d\n", result);
  }

  public static int resolve(int max) {
    int x = 1;
    int y = 2;
    int sum = y;

    while (y < max) {
      int x1 = y;
      int y2 = x + y;

      if (y2 % 2 == 0) {
        sum += y2;
      }

      x = x1;
      y = y2;
    }

    return sum;
  }
}
