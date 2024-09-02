#include <stdio.h>
#include <string.h>
#include <ctype.h>

void InitializeTheSoundex(const char* name, char* soundex);
void AppendingSoundexCharacters(const char* name, char* soundex, char* prevCode);
void Characters(char character, char* soundex, char* prevCode);
int AppendCode(char code, char prevCode);
void SoundexCode(char* soundex);
char GetSoundexCode(char character);
void GenerateSoundex(const char* name, char* soundex);

void GenerateSoundex(const char* name, char* soundex) {
    if (name == NULL || strlen(name) == 0) {
        strcpy(soundex, "");
        return;
    }
    
    InitializeTheSoundex(name, soundex);
    char prevCode = GetSoundexCode(name[0]);
    
    AppendingSoundexCharacters(name, soundex, &prevCode);
    SoundexCode(soundex);
}

void InitializeTheSoundex(const char* name, char* soundex) {
    soundex[0] = toupper(name[0]);
    soundex[1] = '\0';
}

void AppendingSoundexCharacters(const char* name, char* soundex, char* prevCode) {
    int length = strlen(name);
    for (int i = 1; i < length && strlen(soundex) < 4; i++) {
        Characters(name[i], soundex, prevCode);
    }
}

void Characters(char character, char* soundex, char* prevCode) {
    if (isalpha(character)) {
        char code = GetSoundexCode(character);
        if (AppendCode(code, *prevCode)) {
            int len = strlen(soundex);
            soundex[len] = code;
            soundex[len + 1] = '\0';
            *prevCode = code;
        }
    }
}

int AppendCode(char code, char prevCode) {
    return code != '0' && code != prevCode;
}

void SoundexCode(char* soundex) {
    while (strlen(soundex) < 4) {
        int len = strlen(soundex);
        soundex[len] = '0';
        soundex[len + 1] = '\0';
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

int main() {
    char name[100];
    char soundex[5];

    printf("Enter a name: ");
    scanf("%s", name);

    GenerateSoundex(name, soundex);

    printf("Soundex code: %s\n", soundex);

    return 0;
}
