
import junit.framework.TestCase;
import java.util.ArrayList;

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
       System.out.println("MANUAL TESTING:");
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("http://www.google.com - " + urlVal.isValid("http://www.google.com"));    //True
       System.out.println("http://www.google.com:80 - " + urlVal.isValid("http://www.google.com:80"));    //True
       System.out.println("http://www.facebook.com - " + urlVal.isValid("http://www.facebook.com"));    //True
       System.out.println("http://15.6349.12 - " + urlVal.isValid("http://15.6349.12"));    //False
       System.out.println("http/www.asdfasdfasdf.com - " + urlVal.isValid("http/www.asdfasdfasdf.com"));    //False       
   }
   
   
   //Scheme - True
   public void testYourFirstPartition()
   {
       //System.out.println("INPUT PARTITIONING TEST:");
     //You can use this function to implement your First Partition testing       
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("http:// - " + urlVal.isValid("http://"));    //True

   }
   
   //Scheme - False
   public void testYourSecondPartition(){
         //You can use this function to implement your Second Partition testing       
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println(":// - " + urlVal.isValid("://"));    //False
   }
   
   //Authority - True
   public void testYourThirdPartition(){
         //You can use this function to implement your Third Partition testing    
       System.out.println("\nINPUT PARTITIONING TEST:");
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("www.google.com - " + urlVal.isValid("www.google.com"));    //True
 }
   
   //Authority - False
   public void testYourFourthPartition(){
         //You can use this function to implement your Fourth Partition testing       
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       System.out.println("aaa - " + urlVal.isValid("aaa"));    //False

 }
   
   public void testIsValid()
   {
       //You can use this function for programming based testing
       //This code heavily influenced by testIsValid() in URLValidatorCorrect code :)
	   boolean finalVal = false;
	   ArrayList<String> correct = new ArrayList<String>();
	   ArrayList<String> notCorrect = new ArrayList<String>();
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       int testCase = 2;
       int intRes = 0;
       int schemeLength = testUrlScheme.length;
       int testItr = testPartsIndex[0];
       int tPartsLength = testPartsIndex.length;
       
       do {
    	   StringBuilder buffT = new StringBuilder();
    	   int itr = 0;
    	   
    	   for (int i = 4; i > 0; i--) {
    		   if (testPartsIndex[i] == testCase) {
    			   testPartsIndex[i - 1]++;
    			   testPartsIndex[i] = intRes;
    		   }
    	   }
    	   
    	   while (itr < tPartsLength) {
    		   buffT.append(testUrlPartsOptions[itr][testPartsIndex[itr]]);
    		   itr++;
    	   }
    	   
    	   testPartsIndex[4]++;
    	   
    	   finalVal = urlVal.isValid(buffT.toString());
    	   
    	   if (!finalVal) {
    		   correct.add(buffT.toString());
    	   } else {
    		   notCorrect.add(buffT.toString());
    	   }
    	   
    	   testItr++;
    	   
       } while (testItr < 16);//< schemeLength);
       
       int printCorrectItr = 0;
       int printInCorrectItr = 0;
       
       System.out.println("Correct URL's:" + "\n");
       
       
       while (printCorrectItr < correct.size()) {
    	   System.out.println(correct.get(printCorrectItr));
    	   printCorrectItr++;
       }
       
       System.out.println("Incorrect URL's:" + "\n");
       
       while (printInCorrectItr < notCorrect.size()) {
    	   System.out.println(notCorrect.get(printInCorrectItr));
    	   printInCorrectItr++;
       }  
       
   }
   
   public void main(String[] argv)
   {
       UrlValidatorTest urlTest = new UrlValidatorTest("test");
       //System.out.println("MANUAL TESTING:");
       urlTest.testManualTest();
       
       //System.out.println("INPUT PARTITIONING:");
       urlTest.testYourFirstPartition();
       urlTest.testYourSecondPartition();
       urlTest.testYourThirdPartition();
       urlTest.testYourFourthPartition();
       
       System.out.println("UNIT TEST:");
       urlTest.testIsValid();
   }
    

//-------------------- Test data for creating a composite URL
/**
 * The data given below approximates the 4 parts of a URL
 * <scheme>://<authority><path>?<query> except that the port number
 * is broken out of authority to increase the number of permutations.
 * A complete URL is composed of a scheme+authority+port+path+query,
 * all of which must be individually valid for the entire URL to be considered
 * valid.
 * */
 
   String[] testUrlScheme = {"http://", 
           "ftp://", 
           "h3t://", 
           "3ht://", 
           "http:/", 
           "http:", 
           "http/", 
           "://", 
           ""
          };

String[] testUrlAuthority = {"www.google.com",
              "go.com", 
              "go.au", 
              "0.0.0.0", 
              "255.255.255.255", 
              "256.256.256.256", 
              "255.com", 
              "1.2.3.4.5", 
              "1.2.3.4.", 
              "1.2.3", 
              ".1.2.3.4", 
              "go.a", 
              "go.a1a", 
              "go.1aa", 
              "aaa.", 
              ".aaa",
              "aaa",
               ""
             };

String[] testUrlPort = {":80",
         ":65535",
         ":0",
         ":-1",
         ":65636",
         ":65a",
         ""
        };

String[] testUrlPathOptions = {"/test1",
                "/t123",
                "/$23",
                "/..",
                "/../", 
                "/test1/",
                "/#",
                "/test1/file",
                "/t123/file",
                "/$23/file", 
                "/../file",
                "/..//file",
                "/test1//file",
                "/#/file",
                 ""
               };

String[] testUrlQuery = {"?action=view",
          "?action=edit&mode=up",
          ""
         };

String[][] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
int[] testPartsIndex = {0, 0, 0, 0, 0};

}


