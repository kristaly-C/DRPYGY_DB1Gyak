package fileolvas;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class KCSEFileOlvas {
 
	public static void main(String[] args) {
		File in = new File("kristaly.txt");
		File out = new File("kristalyKI.txt");
		 ArrayList<Integer> data = new ArrayList<Integer>();
		 int summa =0;
		 	
		 try {
			data = readFromFile(in);
		} catch (IOException e) {
			e.printStackTrace();
		}	
		summa = ArraySum(data);
		for (int i = 0; i < data.size(); i++) {
			System.out.println((i+1) + ".elem: "+ data.get(i));
		}
		System.out.println("Osszege: " + summa);
		
		try {
			writeInFile(out, data);
		} catch (Exception e) {
			// TODO: handle exception
		}
		
	}
 
 
 


private static void writeInFile(File file, ArrayList<Integer> datas) throws IOException{
	FileWriter fileWriter = new FileWriter(file);
	int summa = 0;
	summa = ArraySum(datas);
	try {
		fileWriter.write(String.valueOf(summa));
		//fileWriter.flush();
	} catch (IOException e) {
		// TODO: handle exception
		System.out.println("Error in writing file...");
	}finally {
		fileWriter.close();
	}
	
}
	
	
private static ArrayList<Integer> readFromFile(File file) throws IOException{
	ArrayList<Integer> datas = new ArrayList<>();
	FileReader fileReader = new FileReader(file);
	BufferedReader reader = new BufferedReader(fileReader);
	String line;
	
	try {
		while ((line = reader.readLine()) != null) {
			datas.add(Integer.parseInt(line));
		}
	} catch (Exception e) {
		System.out.println("Error reading file.." + e.getMessage());
	} finally {
		reader.close();
	}
	
	return datas;
	}


private static int ArraySum(ArrayList<Integer> datas) {
	int osszeg = 0;
	for (Integer line : datas) {
		osszeg += line;
	}
	return osszeg;
	}
}