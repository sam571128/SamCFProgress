import java.util.*;
import java.util.regex.*;
public class HELPMATH {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] a = sc.next().split(Pattern.quote("+"));
		int[] b = new int[a.length];
		for(int i = 0;i < a.length;i++) {
			b[i] = Integer.parseInt(a[i]);
		}
		Arrays.sort(b);
		System.out.print(b[0]);
		for(int i = 1;i < b.length;i++) {
			System.out.print("+"+b[i]);
		}
	}
}
