import java.util.Scanner;   
   

public class CaesarCipherExample   
{   
    
    public static final String ALPHABET = "abcdefghijklmnopqrstuvwxyz";   
      
    public static String encryptData(String inputStr, int shiftKey)   
    {   
        // convert inputStr into lower case   
        inputStr = inputStr.toLowerCase();   
          
        // encryptStr to store encrypted data   
        String encryptStr = "";   
          
        // use for loop for traversing each character of the input string   
        for (int i = 0; i < inputStr.length(); i++)   
        {   
            // get position of each character of inputStr in ALPHABET   
            int pos = ALPHABET.indexOf(inputStr.charAt(i));   
              
            // get encrypted char for each char of inputStr   
            int encryptPos = (shiftKey + pos) % 26;   
            char encryptChar = ALPHABET.charAt(encryptPos);   
              
            // add encrypted char to encrypted string   
            encryptStr += encryptChar;   
        }   
          
        // return encrypted string   
        return encryptStr;   
    }   
      
    // create decryptData() method for decrypting user input string with given shift key   
    public static String decryptData(String inputStr, int shiftKey)   
    {   
        // convert inputStr into lower case   
        inputStr = inputStr.toLowerCase();   
          
        // decryptStr to store decrypted data   
        String decryptStr = "";   
          
        // use for loop for traversing each character of the input string   
        for (int i = 0; i < inputStr.length(); i++)   
        {   
              
            // get position of each character of inputStr in ALPHABET   
            int pos = ALPHABET.indexOf(inputStr.charAt(i));   
              
            // get decrypted char for each char of inputStr   
            int decryptPos = (pos - shiftKey) % 26;   
              
            // if decryptPos is negative   
            if (decryptPos < 0){   
                decryptPos = ALPHABET.length() + decryptPos;   
            }   
            char decryptChar = ALPHABET.charAt(decryptPos);   
              
            // add decrypted char to decrypted string   
            decryptStr += decryptChar;   
        }   
        // return decrypted string   
        return decryptStr;   
    }   
      
    // main() method start   
    public static void main(String[] args)   
    {   
        // create an instance of Scanner class   
        Scanner sc = new Scanner(System.in);   
          
        // take input from the user   
        System.out.println("Enter a string for encryption using Caesar Cipher: ");   
        String inputStr = sc.nextLine();   
          
        System.out.println("Enter the value by which each character in the plaintext message gets shifted: ");   
        int shiftKey = Integer.valueOf(sc.nextLine());   
          
        System.out.println("Encrypted Data ===> "+encryptData(inputStr, shiftKey));   
        System.out.println("Decrypted Data ===> "+decryptData(encryptData(inputStr, shiftKey), shiftKey));   
          
        // close Scanner class object   
        sc.close();   
    }   
}   
