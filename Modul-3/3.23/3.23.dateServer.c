package com.company;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class DataServer {
    public static void main(String[] args){
        ArrayList<String> quotes = new ArrayList<String>();
        ServerSocket serverSocket;
        Socket clientSocket;
        PrintWriter out;
        BufferedReader in;
        quotes.add("It is not in the stars to hold our destiny but in ourselves.|William Shakespeare");
        quotes.add("You can't blame gravity for falling in love.|Albert Einstein");
        quotes.add("Knowledge comes, but wisdom lingers.|Alfred Lord Tennyson");
        quotes.add("Always forgive your enemies - nothing annoys them so much.|Oscar Wilde");
        quotes.add("Freedom lies in being bold.|Robert Frost");
        quotes.add("An eye for an eye will only make the whole world blind.|Mahatma Gandhi");
        try{
            serverSocket = new ServerSocket(6017);
            while (true){
                clientSocket = serverSocket.accept();
                out = new PrintWriter(clientSocket.getOutputStream(), true);
                int randNumber = (int)(Math.random()*quotes.size());
                String quoteOfTheDay = quotes.get(randNumber);
                out.println(quoteOfTheDay);
                out.close();

            }
            } catch (IOException ioe) {
                System.err.println(ioe);
            }
    }
}
