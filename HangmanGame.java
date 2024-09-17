import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class HangmanGame {

    public static void main(String[] args) {

        int attempts = 0;

        Set<String> previousGuesses = new HashSet<>();

        Scanner input = new Scanner(System.in);
        System.out.println("Enter your word to guess: ");
        String wordToGuess = input.nextLine().toUpperCase();
        int length = wordToGuess.length();

        char[] wordToGuessChars = wordToGuess.toCharArray(); //creates char array of string

        //creates and prints an array of chars with the same length as string
        char[] censor = wordToGuess.toCharArray();
        System.out.println("Your secret word is: ");

        for (int index = 0; index < length; index++) {
            censor[index] = '*';
        }

        //Main loop to take guesses (is this while loop the ideal loop here?
        while (!String.valueOf(censor).equals(wordToGuess)) {

            //Initialize all variables in loop
            boolean correct = false; //required for if loops below/lets the user know if the letter is in the word or not
            boolean repeated = false; //check if user guessed the same letter twice

            //prints the censored secret word
            for (int a = 0; a < length; a++) {
                System.out.print(censor[a]);
            }
            System.out.println();

            //asks user for guess, then stores guess in Char charguess and String tempstring
            System.out.println("Type your guess: ");
            String currentGuess = input.next().toUpperCase().substring(0, 1);
            char currentGuessChar = currentGuess.charAt(0); //gets char data from scanner

            //checks if user already guessed the letter previously
            if (previousGuesses.contains(currentGuess)) {
                System.out.println("You already guessed this letter! Guess again. Your previous guesses were: ");
                System.out.println(previousGuesses.stream().reduce("", String::concat));
                repeated = true;
            }

            previousGuesses.add(currentGuess);

            //if the guess is not a duplicated guess, checks if the guessed letter is in the word
            if (!repeated) {
                int times = 0; //number of times a letter is in the word
                for (int index = 0; index < length; index++) {
                    if (wordToGuessChars[index] == currentGuessChar) {
                        censor[index] = currentGuessChar;  //replaces * with guessed letter in caps
                        correct = true;
                        times++;
                    }
                }
                if (correct) {
                    System.out.println("The letter " + currentGuessChar + " is in the secret word! There are " + times + " " + currentGuessChar + " 's in the word. Revealing the letter(s): ");
                } else {
                    System.out.println("Sorry, the letter is not in the word. Your secret word:  ");
                }
                System.out.println();
            }
            attempts++;
        }
        System.out.println("You guessed the entire word " + wordToGuess.toUpperCase() + " correctly! It took you " + attempts + " attempts!");
    }
}
