#Hangman 
### Made by Jean Tu 
<a href="mailto:tujean27@gmail.com?subject=HangManProject">tujean27@gmail.com </a> 
### Finished 29 December 2015 

##Listed below are the instruction on how to run the program

I have supplied a "makefile" for this program, so all you have to do is simply download the folder and type in "make" (if your compiler should allow you to). 

This will then create an executable for you to run: `./hangman`. But you will also need to supply an input file with the executable so it would have to be `./hangman input.txt` or if not input.txt, it will be what you have choosen your input file to be called. 

The format of the input file should be

```
<topic> 
<word> <hint>
<word> <hint>
<word> <hint>
<word> <hint>
```

The topic is so that player is able to know how what they should be guessing the context of the word should be in, and the hint is to help the player a little further beacause the topic isn't that helpful of a clue. 

The input file that I have provided looks like this: 

```
school 
pen something you use to write with
pencil something you use to write with
erase something you use to get rid of mistakes
whiteout something you use to get rid of mistakes 
paper something that you write on
notebook bundles of paper that come in a spiral
journal another name for notebook
notes something that you do during class take _____
laptop what you use to type on, on the go
```

with `school` being the topic and `pen` being the word that the person is trying to guess and `something you use to write with` being the clue. You can make the hints as easy or advanced as you would like. 

##Here are the details of my program
I used a map to be able to store the words and hints from the input file provided. I also use a vector to store just the words because I use a random number generator to generate a number that will choose an index for the word and I search for the word from the map and store the word and hint in a local variable. 

I give a fair number of guesses --being the number of letters in a word, which gives the player a big advantage if there is a word with multiple repeating letters.

I have a set that stores the incorrect letters guessed by the user and it gets displayed evertime the user makes a guess (correct & incorrect) and even if they are just asking to view the hint one more time. 

