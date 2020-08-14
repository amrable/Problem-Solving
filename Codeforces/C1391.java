import java.util.*;
import java.io.*;

public class C1391 {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int n = sc.nextInt();
		long sub = modPow2(n-1);
		long fac = 1;
		for (int i = 2; i <= n; i++) {
			fac = (fac * i) % mod;
		}
		pw.println((fac - sub + mod) % mod);
		pw.close();

	}

	static int mod = (int) 1e9 + 7;

	public static long modPow2(int e) {
		if (e == 0)
			return 1;
		long prev = modPow2(e / 2);
		if (e % 2 == 0) {
			return (prev * prev) % mod;
		} else {
			return (2 * prev * prev) % mod;
		}
	}

	static class Scanner {
		BufferedReader br;
		StringTokenizer st;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(FileReader f) {
			br = new BufferedReader(f);
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public int[] nextIntArr(int n) throws IOException {
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = Integer.parseInt(next());
			}
			return arr;
		}

	}

}
