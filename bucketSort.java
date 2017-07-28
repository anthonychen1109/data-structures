package bucketSort;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class bucketSort {

	int minData;
	int maxData;
	int bucketSize;
	int offSet;
	int[] bucketAry;
	int index;

	public bucketSort() {
	}// bucketSort constructor
	public bucketSort(int min, int max){
		minData = min;
		maxData = max;
	}
	public bucketSort(int bucketSize) {
		bucketAry = new int[bucketSize + 1];
	}// bucketSort constructor

	public void findMinMax(int data) {
		if (data > maxData) {
			maxData = data;
	
		}// if
		if (data < minData) {
			minData = data;
		}// if
	}// findMinMax method

	public int getIndex() {
		return index;
	}// getIndex method

	public void printSortedData(int[] bucketAry, int bucketSize, int offSet,
			String arg) throws IOException {
		int printValue = 0;
		try {
			PrintWriter outFile1 = new PrintWriter(new FileWriter(arg));
			for (int i = 0; i <= bucketSize; i++) {
				while (bucketAry[i] != 0) {
					printValue = i + offSet;
					outFile1.println("printValue " + printValue);
					bucketAry[i]--;
				}// while
			}// for
			outFile1.close();
		}// try
		
		catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}// catch
	}// printSortedData function
	public void test(){
		//System.out.println("fasfd");
		for (int i = 0; i < bucketSize; i++){
			System.out.println(bucketAry[i]);
		}
	}

	public void printBucketAry(int[] bucketAry, int bucketSize, String arg) throws IOException {
		try {
			//test();
			PrintWriter outFile2= new PrintWriter(arg);
			outFile2.println("index ");
			for (int i = 0; i <= 18; i++) {
				// outFile2.width(3);
				outFile2.print(i + " ");
			}// for
			outFile2.println();
			outFile2.println("bucketAry index ");
			for (int i = 0; i <= 18; i++) {
				// outFile2.width(3);
				outFile2.print(bucketAry[i] + " ");
			}// for
			outFile2.close();
		}//try 
		catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}//catch
	}// printBucketAry
}// class
