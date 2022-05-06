
import java.util.Scanner; 
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t;
        t=in.nextInt();
        int c=1;
        while (t-->0) {
            int n= in.nextInt(), p = in.nextInt();
            System.out.format("Case %d: %d\n",c++,n+p);
        }
    }
}