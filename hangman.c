#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void start_game() {
    char secret_word[100];
    char hide_word[100];
    char letter;
    int error_left = 11;

    if (!charge_random_word(secret_word)) {
        printf("Error in loading random word.\n");
        return;
    }

    for (int i = 0; i < strlen(secret_word); i++) {
        hide_word[i] = '_';
    }

    hide_word[strlen(secret_word)] = '\0';

    while (error_left > 0 && strcmp(secret_word, hide_word) != 0) {
        show_stat(hide_word, error_left);

        printf("Enter a letter: ");
        scanf(" %c", &letter);

        if (!verify_letter(letter, secret_word, hide_word)) {
            error_left--;
            printf("This letter is not in the word.\n");
        } else {
            printf("This letter is in the word.\n");
        }
    }

    if (strcmp(secret_word, hide_word) == 0) {
        printf("\nCONGRATULATIONS! You found the word: %s\n", secret_word);
    } else {
        printf("\nYOU LOSE! The word was: %s\n", secret_word);
    }
}

int charge_random_word(char *word) {
    const char *words[] = {
        "elephant", "girafe", "herisson", "kangourou", "loutre",
        "moustique", "panda", "tortue", "zebre", "baguette",
        "chocolat", "croissant", "fromage", "gateau", "pamplemousse",
        "pomme", "riz", "salade", "bibliotheque", "chandelier",
        "echelle", "fauteuil", "parapluie", "telephone", "trompette",
        "voiture", "bleu", "jaune", "mauve", "orange", "pourpre",
        "rouge", "turquoise", "vert", "allemagne", "bresil", "canada",
        "egypte", "france", "japon", "maroc", "suede", "abeille",
        "aventure", "brouillard", "chanson", "escalier", "fantome",
        "liberte", "pyramide", "sorciere", "voyage"
    };
    int count = sizeof(words) / sizeof(words[0]);

    srand(time(NULL));
    strcpy(word, words[rand() % count]);

    return 1;
}

int show_stat(char hide_word[], int error_left) {
    printf("\nWord to guess: %s\n", hide_word);
    printf("Attempts left: %d\n", error_left);
    return 0;
}

int verify_letter(char letter, char secret_word[], char hide_word[]) {
    int right = 0;

    for (int i = 0; i < strlen(secret_word); i++) {
        if (tolower(secret_word[i]) == tolower(letter)) {
            hide_word[i] = secret_word[i];
            right = 1;
        }
    }
    return right;
}
