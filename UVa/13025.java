// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4913
import java.util.*;
class Main {
	public static void main(String[] args) {
		String[] names = new String[] {
			"", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" 
		};
		Calendar day = new GregorianCalendar(2013, 4, 29);
		System.out.println("May 29, 2013 " + names[day.get(Calendar.DAY_OF_WEEK)]);
	}
}