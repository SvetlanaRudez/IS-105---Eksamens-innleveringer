package com.company;
import java.net.*;
import java.io.*;

public class DateClient {
    public static void main(String[] args) {
        Socket serverSocket;
        PrintWriter out;
        BufferedReader in;
        try{
            serverSocket = new Socket("127.0.0.1", 6017);
            in = new BufferedReader(new InputStreamReader(serverSocket.getInputStream()));
            String quoteOfTheDay = in.readLine();
            System.out.println(quoteOfTheDay);
            serverSocket.close();

        } catch (IOException ioe) {
            System.err.println(ioe);
        }

    }
}
