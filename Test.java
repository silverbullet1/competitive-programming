// import java.io.*;
// public class Test implements AutoCloseable {
// 	public static void main(String[] args) throws Exception {
//     System.out.println(Test.test());
// }
// public void close() throws IOException {

// }

// public static int test() throws Exception {
// 	int a;
//     try(Test t=new Test()) {
//          return 0;
//     }
// finally {
// 	return 1;
// }
// }
// }
public class Test {
public static String foo(){
System.out.println("Test foo called");
return "";
}
public static void main(String args[]){
Test obj = new Test();
System.out.println(obj.foo());
}
}