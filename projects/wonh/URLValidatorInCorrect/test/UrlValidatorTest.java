
import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   
   //You need to create more test cases for your Partitions if you need to 
   
   
   public void testIsValid()
   {
	   
	   //You can use this function for programming based testing
	   UrlValidator unitUrl = new UrlValidator(null, null, 1);
	   int indicator = 0;
	   String[] unitTests = new String[10];
	   String[] urlList = new String[10];
	   String[] failMsg = new String[10];
	   
	   unitTests[0]="1. Testing a simple valid URL.";
	   urlList[0]="http://www.google.com";      //http scheme
	   failMsg[0]="Fail: simple http URL not recongized.";
	   
	   unitTests[1]="2. The a URL with https scheme.";
	   urlList[1]="https://www.google.com";     //https scheme
	   failMsg[1]="Fail: 2. https scheme not recongized.";
	   
	   unitTests[2]="3. The a URL with ftp scheme.";
	   urlList[2]="ftp://www.google.com";       //ftp scheme
	   failMsg[2]="Fail: 3. ftp scheme not recognized.";
	   
	   unitTests[3]="4. The a URL with h3t scheme.";
	   urlList[3]="h3t://www.google.com";       //h3t scheme
	   failMsg[3]="Fail: 4. h3t scheme not recognized.";
	   
	   unitTests[4]="5. The a URL with :// scheme.";
	   urlList[4]="://www.google.com";          //scheme with only ://
	   failMsg[4]="Fail: 5. Only having :// should be a valid scheme.";          
	   
	   unitTests[5]="6. The a URL with out a scheme.";
	   urlList[5]="www.google.com";             //scheme does not exist 
	   failMsg[5]="Fail: 6. Not have a scheme should be acceptable.";   
	   
	   unitTests[6]="7. The a URL that is not Google.";
	   urlList[6]="www.yahoo.com";              //not a google website
	   failMsg[6]="Fail: 7. It doesn't have to be Google!.";   
	   
	   unitTests[7]="8. The a URL with a port number.";
	   urlList[7]="www.google.com:80";          //port number exists
	   failMsg[7]="Fail: 8. Port number should be allowed.";   
	   
	   unitTests[8]="9. The a URL with a path.";
	   urlList[8]="www.google.com/abc";         //path exists
	   failMsg[8]="Fail: 9. URL is allowed to have a path(s)."; 
	   
	   unitTests[9]="10. The a URL with a query.";
	   urlList[9]="www.google.com?action=view"; //query exists
	   failMsg[9]="Fail: 10. Query should be alloed."; 
	   
	   boolean result = false;
	   
	   System.out.println("The 10 tests listed below will be executed.  Because of the bug in the current testing, the test will stop executing when a failure is encountered.");
	   System.out.println("Test immediately following the last passed test shall be considered as a failed test; all subsequent tests shall be considered as not tested.\n");
	   
	   for (int i = 0; i < 10; i++)
	   {
		   System.out.println(unitTests[i]);
	   }
	   
	   System.out.println("\nTest results:\n");
	   
	   for (int i = 0; i < 10; i++)
	   {
		   try {
			   if(unitUrl.isValid(urlList[i]) == true)
			   {
				   result = true;
			   }
			   
			   if(result == true)
			   {
				   System.out.println("PASS: "+unitTests[i]);
			   } else {
				   System.out.println(failMsg[i]);
			   }
			   
			   result = false;
		   }
		   catch (Throwable t) {
			   System.out.println(failMsg[i]);
		   }
		   
		   result = false;
	   }
	    
   }
  


}
