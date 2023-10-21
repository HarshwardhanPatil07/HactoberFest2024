// vineeTagarwaL-code
// a program to print IP address and host name
// 20th oct , 2023

import java.net.InetAddress;
import java.net.UnknownHostException;

public class IpAddress {



    public static void main(String[] args) throws UnknownHostException  {

        getHost();
    }

    static void getHost() throws UnknownHostException{
        InetAddress ip = InetAddress.getLocalHost();
        System.out.println("Host : "+ip.getHostName() );
        System.out.println("Host 2 "+ip.getCanonicalHostName());
        System.out.println("Ip of my system is : " +ip.getHostAddress() );



    }
}
