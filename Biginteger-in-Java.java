package Algorithm;

import java.math.BigInteger;

/* Big Integer Class in Java | powerful lot of inbuilt functions */

/*
Modular Arithmetic
GCD Calculation
Base Conversion
Power Calculation
Bitwise Operators
Prime Generation
and more
*/


import java.util.Scanner;
public class Biginteger_in_Java {

    static void playWithBigInt(){
        Scanner sc = new Scanner(System.in); 
        String s1 = sc.next(); //
        
        BigInteger b1 = new BigInteger(s1);
        BigInteger b2 = new BigInteger("4799124612354");

        b1 = b1.add(b2); 
        System.out.println("Add : " + b1); 
        System.out.println("Mul : " + b1.multiply(b2)); 
        System.out.println();

        // Bit count - Total set bits
        System.out.println( b1.bitCount() );

        // Total no. of bits
        System.out.println( b1.bitLength() );
        System.out.println();

        //Integer into BigInteger
        int a = sc.nextInt(); //
        int b = sc.nextInt(); //
        System.out.println(a+b);

        BigInteger b3 = BigInteger.valueOf(a);
        BigInteger b4 = BigInteger.valueOf(b);

        // Print Gcd of BigInteger
        System.out.println(b3.gcd(b4));

        // power of BigInteger - BigNum ^ x -> x should be integer
        System.out.println( b3.pow(20));
        System.out.println();

        // Base Conversion
        BigInteger b5 = new BigInteger("1010", 2);
        System.out.println(b5); // 10

        BigInteger b6 = new BigInteger("53", 8);
        System.out.println(b6); // 43       

        sc.close(); 
    }

    static BigInteger fact( int N ){
        BigInteger b = new BigInteger("1");
        for( int i=2; i<=N; i++ ){
            b = b.multiply(BigInteger.valueOf(i));
        }
        return b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // // BigInteger inJava
        // playWithBigInt();
    
        System.out.println(fact(5)); // 120
        System.out.println(fact(7)); // 5040
        System.out.println(fact(100)); // 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000

        sc.close();
    }
    
}