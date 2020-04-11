
/*Eager initalization..creates object whenever the class is loaded onto the JVM
	Very simple to implement 
	BUT
	Leads to resource wastage..instance created even if it might not be needed at all
	Wastage of CPU time
	Doesn't work in multithreading environment
*/
public class Singleton {
	private static instance = new Singleton();
	private Singleton() { 
	}
	public static getInstance() {
		return instance;
	}
	// Can also use static block for returning instance..getInstance method is not really needed
}

/* Lazy initialization
	Object is created only if it is needed. It may overcome resource overcome and wastage of CPU time.
	Doesn't work in multithreading environment
*/
public class Singleton {
	private static instance = null;
	private Singleton() {

	}
	public static getInstance() {
		if(instance == null)
			return instance = new Singleton();
	}
}

/* Thread safe implementation
	getInstance() method is synchronized so it causes slow performance as multiple threads can’t access it simultaneously.
*/
public class Singleton {
	private static instance = null;
	private Singleton() {

	}
	synchronized public static getInstance() { //All the threads will be waiting here since the function itself is locked
		if(instance == null)
			return instance = new Singleton();
	}
}

// Double phase locking
public class Singleton {
	private static instance = null;
	private Singleton() {

	}
	public static getInstance() { 
		if(instance == null) { //Most of the threads will return from here itself
			synchronized(Singleton.class) {
				if(instance == null) { //Check again because there is a chance that more than 1 thread might have entered together
					instance = new Singleton();
				}
			}
		}
		return instance;
	}
}