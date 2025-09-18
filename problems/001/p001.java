
public class p001 {
  public static void main(String[] args) {
   
    int result = resolve(3, 5, 1000);

    System.out.printf("Result=%d\n", result);
  }

  public static int resolve(int n1, int n2, int limit) {
    int sum = 0;
    for (int i = n1; i < 1000; i++) {

      if (i % n1 == 0 || i % n2 == 0) {
        sum += i;
      }

    }
    return sum;
  }
}
