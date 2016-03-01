import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class P11278 {
	public static void main(String[] args) {
		Map<Character, Character> m = new HashMap<Character, Character>();
		m.put('`', '`'); m.put('1', '1'); m.put('2', '2'); m.put('3', '3'); m.put('q', '4'); m.put('j', '5'); m.put('l', '6');
		m.put('m', '7'); m.put('f', '8'); m.put('p', '9'); m.put('/', '0'); m.put('[', '-'); m.put(']', '=');
		
		m.put('4', 'q'); m.put('5', 'w'); m.put('6', 'e'); m.put('.', 'r'); m.put('o', 't'); m.put('r', 'y');
		m.put('s', 'u'); m.put('u', 'i'); m.put('y', 'o'); m.put('b', 'p'); m.put(';', '['); m.put('=', ']'); m.put('\\', '\\');
		
		m.put('7', 'a'); m.put('8', 's'); m.put('9', 'd'); m.put('a', 'f'); m.put('e', 'g'); m.put('h', 'h'); m.put('t', 'j'); m.put('d', 'k');
		m.put('c', 'l'); m.put('k', ';'); m.put('-', '\'');
		
		m.put('0', 'z'); m.put('z', 'x'); m.put('x', 'c'); m.put(',', 'v'); m.put('i', 'b'); m.put('n', 'n'); m.put('w', 'm'); m.put('v', ',');
		m.put('g', '.'); m.put('\'', '/');
		
		//////////////////////////////////////////////
		
		m.put('~', '~'); m.put('!', '!'); m.put('@', '@'); m.put('#', '#'); m.put('Q', '$'); m.put('J', '%'); m.put('L', '^');
		m.put('M', '&'); m.put('F', '*'); m.put('P', '('); m.put('?', ')'); m.put('{', '_'); m.put('}', '+');
		
		m.put('$', 'Q'); m.put('%', 'W'); m.put('^', 'E'); m.put('>', 'R'); m.put('O', 'T'); m.put('R', 'Y'); m.put('S', 'U');
		m.put('U', 'I'); m.put('Y', 'O'); m.put('B', 'P'); m.put(':', '{'); m.put('+', '}'); m.put('|', '|');
		
		m.put('&', 'A'); m.put('*', 'S'); m.put('(', 'D'); m.put('A', 'F'); m.put('E', 'G'); m.put('H', 'H'); m.put('T', 'J'); m.put('D', 'K');
		m.put('C', 'L'); m.put('K', ':'); m.put('_', '"');
		
		m.put(')', 'Z'); m.put('Z', 'X'); m.put('X', 'C'); m.put('<', 'V'); m.put('I', 'B'); m.put('N', 'N'); m.put('W', 'M'); m.put('V', '<'); 
		m.put('G', '>'); m.put('"', '?');  
		//////////////////////////
		
		m.put(' ', ' ');
	    Set<Character> s1 = m.keySet();
		Map<Character, Character> m2 = new HashMap<Character, Character>();
		for(Character ch : s1)
			m2.put(m.get(ch), ch);
		
		
		Scanner in = new Scanner(System.in);
		while(in.hasNextLine()) {
			String s = in.nextLine();
			int len = s.length();
			for(int i=0; i<len; i++) 
				System.out.printf("%c",m2.get(s.charAt(i)));
			System.out.printf("\n");
			
		}
		

	}
}
