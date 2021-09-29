package fileolvas;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class KCSEFileOlvas {
 
	public static void main(String[] args) {
		File out = new File("kristaly.txt");
		ArrayList<Integer> data = new ArrayList<Integer>();
		int darabszam;
		
		Scanner in = new Scanner(System.in);
		System.out.print("Adatok száma = ");
		darabszam = in.nextInt();
		
		for (int i = 0; i < darabszam; i++) {
			System.out.println((i+1) + ".adat = ");
			data.add(in.nextInt());
			
		}
		
		try {
			writeInFile(out, data);
		} catch (Exception e) {
			// TODO: handle exception
		}
		
	}
 
 
 


private static void writeInFile(File file, ArrayList<Integer> datas) throws IOException{
	FileWriter fileWriter = new FileWriter(file);

	try {
		for (int i = 0; i < datas.size(); i++) {
			fileWriter.write(String.valueOf(datas.indexOf(i)));	
		}
		
		//fileWriter.flush();
	} catch (IOException e) {
		// TODO: handle exception
		System.out.println("Error in writing file...");
	}finally {
		fileWriter.close();
	}
	
}
}