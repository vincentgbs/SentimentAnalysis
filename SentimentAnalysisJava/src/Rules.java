import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Rules {

	public Scanner read = new Scanner(System.in);
	final int MAX = 7;
	
	public Map<String, String[]> readToTable(String filename) {
		Map<String, String[]> db = new HashMap<String, String[]>();
		File fileIn = new File(filename);
		try {
			int ctr = 0;
			Scanner scanner = new Scanner(fileIn);
			while (scanner.hasNextLine() && ctr < MAX) {
				String line = scanner.nextLine();
				String[] stringTokenizer = line.split(",");
				if (stringTokenizer.length > 0) {
					db.put(stringTokenizer[0], stringTokenizer);
					ctr++;
				}
			}
			scanner.close();
		} catch (FileNotFoundException e) {
			System.out.println("The "+filename+" file must be in the current working directory.");
		} catch (Exception e) {
			e.printStackTrace();
		}
		return db;
	}
	
	public String test(String review) {
		if (review == "") {
			return "positive";
		} else {
			return "negative";
		}
	}
	
	public void labelReview() {
		System.out.println("Enter a review:");
		String review = read.nextLine();
		String rating = this.test(review);
		System.out.println("This is a " + rating + " review.");
	}
	
	public static void main(String[] args) {
		Rules demo = new Rules();
//		demo.labelReview();
		Map<String, String[]> test = demo.readToTable("library/LoughranMcDonald_MasterDictionary_2018.csv");
		Set<String> keys = test.keySet();
		Iterator<String> i = keys.iterator();
		while (i.hasNext()) {
			String print = Arrays.toString(test.get(i.next()));
			System.out.println(print);
		}
	}

}
