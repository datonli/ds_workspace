package basic;


/**
 * Passing a parameter to a method,it's always the copy of parameter passing.
 * What's different between primitive type and object type is :
 * 			copy a primitive type is just a copy,but copy a object type is a reference of object!
 * Whatever you change the primitive copy wouldn't effect the real , original value,
 * but change the value of object reference , I mean change the value that the reference refer to,
 * (specific ,copy a object is same as assignment to another object.
 *    SpecificObject so = s;
 *    then so and s will refer to the same address!
 *    what operate with so is the same as operate with s!!!
 * )
 *  will change real value. 
 * @author Daniel Li
 *
 */
public class MethodParaments {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int salary = 10;
		Money m = new Money(10);
		triple(salary);
		triple(m);
		System.out.println("Salary is " + salary);
		System.out.println("Money's Salary is " + m.salary);
	}

	public static void triple(int salary){
		salary = salary*3;
	}
	
	public static void triple(Money m)
	{
		m.salary = m.salary*3;
	}
}


class Money{
	int salary;
	Money(int s)
	{
		this.salary = s;
	}
}