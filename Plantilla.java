import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Plantilla {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("input.in"));
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		//quitar para salida estandar
		PrintWriter writer = new PrintWriter("output.out");
	


		StringBuilder out = new StringBuilder();
		String line = "";
		while ((line = in.readLine()) != null) {

			// Faster than System.out.printl
			int n = 1000;
			for (int i = 0; i < n; i++)
				out.append(n + "\n");
			
		}

		writer.print(out);
		writer.close();
		in.close();
	}

	public static int[] readInts(String line) {
		StringTokenizer st = new StringTokenizer(line.trim());
		int a[] = new int[st.countTokens()], index = 0;
		while (st.hasMoreTokens())
			a[index++] = Integer.parseInt(st.nextToken());
		return a;
	}
}
