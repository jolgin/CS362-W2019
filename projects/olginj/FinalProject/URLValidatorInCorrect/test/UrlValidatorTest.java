

import junit.framework.TestCase;
import java.util.Random;

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
	   
	   
	   UrlValidator urlval = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
	   String[] schemes = {"https://","ftp://"};
	   String[] invalidSchemes = {"zfg://","5fd://","http:/"};
	   String[] hostname = {"www.stackoverflow.com","www.yahoo.com","www.github.com"};
	   String[] invalidHostname = {"xxsa","netflix.fds","1.3.2"};
	   String[] port = {":50",":100"};
	   String[] invalidPort = {":-40",":abcde",":10t"};
	   String[] path = {"/science","/computer","/gallery"};
	   String[] invalidPath = {"///","/../","//file"};
	   String[] query = {"?table","?five","?id=4356"};
	   
	   
	   for(int i = 0; i < 30; i++) {
		   Random rand = new Random();
		   
		   int valOrInval1 = rand.nextInt(2);
		   int valOrInval2 = rand.nextInt(2);
		   int valOrInval3 = rand.nextInt(2);
		   int valOrInval4 = rand.nextInt(2);
		   
		   String UrlScheme, UrlHost, UrlPort, UrlPath, UrlQuery; 
		   
		   int rand1;
		   int rand11;
		   if(valOrInval1 == 0) {
			   rand1 = rand.nextInt(schemes.length);
			   UrlScheme = schemes[rand1];
		   }	
		   else {
			   rand11 = rand.nextInt(invalidSchemes.length);
			   UrlScheme = invalidSchemes[rand11];
		   }
		   
		   
		   int rand2;
		   int rand22;
		   if(valOrInval2 == 0) {
			   rand2 = rand.nextInt(hostname.length);
			   UrlHost = hostname[rand2];
		   }
		   else {
			   rand22 = rand.nextInt(invalidHostname.length);
			   UrlHost = invalidHostname[rand22];
		   }
		   
		   
		   int rand3;
		   int rand33;
		   if(valOrInval3 == 0) {
			   rand3 = rand.nextInt(port.length);
			   UrlPort = port[rand3];
		   }
		   else {
			   rand33 = rand.nextInt(invalidPort.length);
			   UrlPort = invalidPort[rand33];
		   }
		   
		   
		   int rand4;
		   int rand44;
		   if(valOrInval4 == 0) {
			   rand4 = rand.nextInt(path.length);
			   UrlPath = path[rand4];
		   }
		   else {
			   rand44 = rand.nextInt(invalidPath.length);
			   UrlPath = invalidPath[rand44];
		   }
		   
		   int rand5 = rand.nextInt(query.length);
		   UrlQuery = query[rand5];
		   
		   String url = (UrlScheme + UrlHost + UrlPort + UrlPath + UrlQuery);
		   
		   System.out.print("\n" + valOrInval1 + " " + valOrInval2 + " " + valOrInval3 + " " + valOrInval4);
		   
		   if(valOrInval1 == 0 && valOrInval2 == 0 && valOrInval3 == 0 && valOrInval4 == 0) {
			   if(urlval.isValid(url)) {
				   System.out.print("\nPASSED: " + url);
			   }
			   else {
				   System.out.print("\nFAILED: " + url);
			   }
		   }
		   else {
			   if(urlval.isValid(url)) {
				   System.out.print("\nFAILED: " + url);
			   }
			   else {
				   System.out.print("\nPASSED: " + url);
			   }
		   }
	   }
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	 
	   
	   UrlValidator urlval = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
	   String[] schemes = {"","http://","file:"};
	   String[] invalidSchemes = {"","://","htttp:/"};
	   String[] hostname = {"www.google.com","www.netflix.com"};
	   String[] invalidHostname = {"","12345","wzw.netflix","255.-345.322"};
	   String[] port = {"",":3000", ":80", ":100"};
	   String[] invalidPort = {"::",":[]",":32e"};
	   String[] path = {"","/state","/exit"};
	   String[] invalidPath = {"\345","/,,","/\test"};
	   String[] query = {"","?report","?result","?name"};
	   
	   for(int i = 0; i < 30; i++) {
		   Random rand = new Random();
		   
		   int valOrInval1 = rand.nextInt(2);
		   int valOrInval2 = rand.nextInt(2);
		   int valOrInval3 = rand.nextInt(2);
		   int valOrInval4 = rand.nextInt(2);
		   
		   String UrlScheme, UrlHost, UrlPort, UrlPath, UrlQuery; 
		   
		   int rand1;
		   int rand11;
		   if(valOrInval1 == 0) {
			   rand1 = rand.nextInt(schemes.length);
			   UrlScheme = schemes[rand1];
		   }	
		   else {
			   rand11 = rand.nextInt(invalidSchemes.length);
			   UrlScheme = invalidSchemes[rand11];
		   }
		   
		   
		   int rand2;
		   int rand22;
		   if(valOrInval2 == 0) {
			   rand2 = rand.nextInt(hostname.length);
			   UrlHost = hostname[rand2];
		   }
		   else {
			   rand22 = rand.nextInt(invalidHostname.length);
			   UrlHost = invalidHostname[rand22];
		   }
		   
		   
		   int rand3;
		   int rand33;
		   if(valOrInval3 == 0) {
			   rand3 = rand.nextInt(port.length);
			   UrlPort = port[rand3];
		   }
		   else {
			   rand33 = rand.nextInt(invalidPort.length);
			   UrlPort = invalidPort[rand33];
		   }
		   
		   
		   int rand4;
		   int rand44;
		   if(valOrInval4 == 0) {
			   rand4 = rand.nextInt(path.length);
			   UrlPath = path[rand4];
		   }
		   else {
			   rand44 = rand.nextInt(invalidPath.length);
			   UrlPath = invalidPath[rand44];
		   }
		   
		   int rand5 = rand.nextInt(query.length);
		   UrlQuery = query[rand5];
		   
		   String url = (UrlScheme + UrlHost + UrlPort + UrlPath + UrlQuery);
		   
		   System.out.print("\n" + valOrInval1 + " " + valOrInval2 + " " + valOrInval3 + " " + valOrInval4);
		   
		   if(valOrInval1 == 0 && valOrInval2 == 0 && valOrInval3 == 0 && valOrInval4 == 0) {
			   if(urlval.isValid(url)) {
				   System.out.print("\nPASSED: " + url);
			   }
			   else {
				   System.out.print("\nFAILED: " + url);
			   }
		   }
		   else {
			   if(urlval.isValid(url)) {
				   System.out.print("\nFAILED: " + url);
			   }
			   else {
				   System.out.print("\nPASSED: " + url);
			   }
		   }
	   } 	
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
