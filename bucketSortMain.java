package bucketSort;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class main {

	public static void main(String[] args) throws FileNotFoundException{
		  //File inFile = new File(args[0]);
		  String input = args[0];
		  String outFile1=args[1];
		  String outFile2=args[2];
		   // PrintWriter outFile1;
		   // PrintWriter outFile2;
		    int data = 0;
		    int bucketSize;
		    int offSet;
		    int index = 0;
		    int[] bucketAry;
		    int da = 0;
		    bucketSort bucket = new bucketSort(9999,0);
		    
		    Scanner inFile = new Scanner(new FileReader(input));
		/*
		    int nextInt = inFile.nextInt();
		    inFile.nextInt();
		    bucket.minData = data;
		    bucket.maxData = data;
		  */  
		    while(inFile.hasNext()){
		    	data =inFile.nextInt();
		    //	System.out.println(data+" ");
		        bucket.findMinMax(data);
		        
		    }//while
		  //  inFile.close();
		    
		    bucketSize = bucket.maxData - bucket.minData + 1;
		    offSet = bucket.minData;
		   // System.out.println("max " + bucket.maxData);
		   // System.out.println("min " + bucket.minData);
		    bucketSort myBucket = new bucketSort(bucketSize);
		    bucketAry = new int[bucketSize + 1];
		  //  System.out.println("bucket size " + bucketSize);
		    for(int i=0; i<bucketSize+1; i++){ //initialize to 0
		        bucketAry[i]=0;
		    }
		    Scanner infile = new Scanner(new FileReader(input));
		    while(infile.hasNext()){
		    	data = infile.nextInt();
		    //	System.out.println("data "+data);
		        index = data - offSet; //positions to enter data
		  //      System.out.println("intd " +index);
		        bucketAry[index]++;
		    }//while
		    try {
				myBucket.printBucketAry(bucketAry, bucketSize, args[2]);
				myBucket.printSortedData(bucketAry, bucketSize, offSet, args[1]);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		   // myBucket.printSortedData(bucketAry, bucketSize, offSet, output1);
		    
		    //inFile.close();
		    
	}//main
}//class
