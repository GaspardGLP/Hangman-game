#ifndef HANGMAN_H
#define HANGMAN_H

int charge_random_word(char *word);
int show_stat(char hide_word[], int error_left);
int verify_letter(char letter, char secret_word[], char hide_word[]);

void start_game();

#endif HANGMAN_H
