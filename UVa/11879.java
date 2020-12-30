// https://onlinejudge.org/external/118/11879.pdf
import java.util.*;
import java.math.*;
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		final BigInteger md = new BigInteger("17");
		while (true) {
			BigInteger a = sc.nextBigInteger();
			if (a.equals(new BigInteger("0"))) {
				break;
			}
			if (a.mod(md).equals(new BigInteger("0"))) {
				System.out.println(1);
			} else {
				System.out.println(0);
			}
		}
	}
}