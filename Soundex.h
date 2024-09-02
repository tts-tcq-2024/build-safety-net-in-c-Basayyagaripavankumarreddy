#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
void InitializeTheSoundex(char name[], char soundex[]);
void AppendingSoundexCharacters(char name[], char soundex[], char *prevCode);
void Characters(char character, char soundex[], char *prevCode);
char GetSoundexCode(char character);
int AppendCode(char code, char prevCode);
void SoundexCode(char soundex[]);
 
void GenerateSoundex(char name[], char soundex[]) {
    if (name == NULL || strlen(name) == 0) {
        soundex[0] = '\0';
        return;
    }
 
    InitializeTheSoundex(name, soundex);
    char prevCode = GetSoundexCode(name[0]);
    AppendingSoundexCharacters(name, soundex, &prevCode);
    SoundexCode(soundex);
}
 
void InitializeTheSoundex(char name[], char soundex[]) {
    soundex[0] = toupper(name[0]);
    soundex[1] = '\0';
}
 
void AppendingSoundexCharacters(char name[], char soundex[], char *prevCode) {
    for (int i = 1; i < strlen(name) && strlen(soundex) < 4; i++) {
        Characters(name[i], soundex, prevCode);
    }
}
 
void Characters(char character, char soundex[], char *prevCode) {
    if (isalpha(character)) {
        char code = GetSoundexCode(character);
        if (AppendCode(code, *prevCode)) {
            strncat(soundex, &code, 1);
            *prevCode = code;
        }
    }
}
 
char GetSoundexCode(char character) {
    character = toupper(character);
    switch (character) {
        case 'B': case 'F': case 'P': case 'V':
            return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
            return '2';
        case 'D': case 'T':
            return '3';
        case 'L':
            return '4';
        case 'M': case 'N':
            return '5';
        case 'R':
            return '6';
        default:
            return '0';
    }
}
 
int AppendCode(char code, char prevCode) {
    return code != '0' && code != prevCode;
}
 
void SoundexCode(char soundex[]) {
    while (strlen(soundex) < 4) {
        strncat(soundex, "0", 1);
    }
}
