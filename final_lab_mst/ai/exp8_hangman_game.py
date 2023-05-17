import random

def hangman():
    word_list = ["apple", "banana", "cherry", "date", "elderberry", "fig", "grapefruit", "honeydew", "jackfruit", "kiwi"]
    word = random.choice(word_list).lower()
    guessed_letters = []
    tries = 6

    print("Welcome to Hangman!")
    print("_ " * len(word))

    while tries > 0:
        guess = input("Enter a letter: ").lower()

        if len(guess) != 1 or not guess.isalpha():
            print("Invalid input. Please enter a single letter.")
            continue

        if guess in guessed_letters:
            print("You already guessed that letter. Try again.")
            continue

        guessed_letters.append(guess)

        if guess in word:
            print("Correct!")
        else:
            tries -= 1
            print("Wrong guess. You have", tries, "tries left.")

        word_progress = ""
        for letter in word:
            if letter in guessed_letters:
                word_progress += letter + " "
            else:
                word_progress += "_ "

        print(word_progress)

        if "_" not in word_progress:
            print("Congratulations! You won!")
            return

    print("You lost. The word was", word)

hangman()
