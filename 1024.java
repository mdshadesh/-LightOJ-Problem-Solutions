import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
	public static BigInteger GCD (BigInteger a, BigInteger b)
	{
		if (b.equals(BigInteger.valueOf(0)))
		    return a;
		else
	            return GCD (b,a.mod(b));
	}

	public static void main (String[] args)
	{
		Scanner in = new Scanner (System.in);
		int t,pos,n,i;
		BigInteger gcd,lcm;

		t = in.nextInt();

		for (pos=1; pos<=t; pos++)
		{
			n = in.nextInt();

			int []arr = new int [n];

			for (i=0; i<n; i++)
				arr[i] = in.nextInt();

			lcm = BigInteger.valueOf(arr[0]);

			for (i=1; i<n; i++)
			{
				gcd = GCD (lcm,BigInteger.valueOf(arr[i]));
				lcm = (lcm.divide(gcd)).multiply(BigInteger.valueOf(arr[i]));
			}

			System.out.println ("Case " +pos+ ": " +lcm);

			System.gc ();
		}
	}
}