import java.util.Arrays;

class IllegalTriangleException extends IllegalArgumentException {
	public IllegalTriangleException() {}
	public IllegalTriangleException(String msg) { super(msg); }
}

public class Triangolo {
	
	private double[] lato = new double[3];
	
	// (Code smell) = frammento di codice a rischio di errore
	// Esempio: if (a=b)
	
	public Triangolo(double a, double b, double c) {
		if (a+b <= c || b+c <= a || c+a <= b) 
			throw new IllegalTriangleException("Lati non validi.");		
		lato[0] = a;
		lato[1] = b;
		lato[2] = c;
	}
	
	public double getArea() {
		// Formula di Erone
		double p = 0; // semi-perimetro
		// enhanced for
		for (double l: lato) {
			p += l;
		}
		p /= 2;
		return Math.sqrt(p*(p-lato[0])*(p-lato[1])*(p-lato[2]));		
	}
	
	@Override
	public String toString() {
		return Arrays.toString(lato);
	}
	
	public static class Rettangolo extends Triangolo {	
		public Rettangolo(double c1, double c2) {
			super(c1, c2, Math.sqrt(c1*c1 + c2*c2));
		}
	}

	public static class Isoscele extends Triangolo {	
		public Isoscele(double base, double lato) {
			super(base, lato, lato);
		}
	}

	
	// Esempi unchecked:
	//   ArrayIndexOutOfBoundsException
	//   NullPointerException
	//   IllegalArgumentException
	
	// Esempi checked:
	//   IOException
	
	public static void main(String[] args) {
		// Specifica, traccia:
		Triangolo t1 = new Triangolo(10, 11, 12); // lunghezze dei lati
		double area1 = t1.getArea();
		System.out.println(area1);
		System.out.println(t1);
		// Deve lanciare un'eccezione unchecked
		try {
			Triangolo t2 = new Triangolo(10, 4, 6); 
		} catch (IllegalArgumentException e) {
			System.out.println(e);
		}
				               
		Triangolo t3 = new Triangolo.Rettangolo(5, 6); // Cateti
		System.out.println(t3.getArea());
		
		Triangolo t4 = new Triangolo.Isoscele(5, 6); // Base e uno dei lati
		System.out.println(t4.getArea());
		
	}
}

// Generics
// Due modi corretti:
//   ArrayList<Integer> l = new ArrayList<Integer>();
//   ArrayList<Integer> l = new ArrayList<>(); // Operatore diamond

// Due modi non corretti:
//   ArrayList<> l = new ArrayList<>();  // non compila (controllare)
//   ArrayList l = new ArrayList();      // compila con warning






















