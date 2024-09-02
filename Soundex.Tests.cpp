#include <stdio.h>
#include <assert.h>
#include <string.h>

void GenerateSoundex(const char* name, char* soundex);
void InitializeTheSoundex(const char* name, char* soundex);
void AppendingSoundexCharacters(const char* name, char* soundex, char* prevCode);
void Characters(char character, char* soundex, char* prevCode);
int AppendCode(char code, char prevCode);
void SoundexCode(char* soundex);
char GetSoundexCode(char character);

void test_GenerateSoundex_EmptyString_ReturnsEmptyString() {
    char result[5];
    GenerateSoundex("", result);
    assert(strcmp(result, "") == 0);
}

void test_GenerateSoundex_SingleCharacter_ReturnsPaddedCode() {
    char result[5];
    GenerateSoundex("A", result);
    assert(strcmp(result, "A000") == 0);
}

void test_GenerateSoundex_ValidName_ReturnsCorrectSoundex() {
    char result[5];
    GenerateSoundex("Jack", result);
    assert(strcmp(result, "J020") == 0);
}

void test_GenerateSoundex_LongString_ReturnsTruncatedCode() {
    char result[5];
    GenerateSoundex("JackandJill", result);
    assert(strcmp(result, "J020") == 0);
}

void test_GenerateSoundex_NumbersInString_ReturnsCorrectSoundex() {
    char result[5];
    GenerateSoundex("Jack123", result);
    assert(strcmp(result, "J020") == 0);
}

void test_InitializeTheSoundex_ValidName_ReturnsInitializedSoundex() {
    char result[5] = "";
    InitializeTheSoundex("John", result);
    assert(strcmp(result, "J") == 0);
}

void test_AppendingSoundexCharacters_ProcessesCharactersCorrectly() {
    char soundex[5] = "J";
    char prevCode = 'J';
    AppendingSoundexCharacters("John", soundex, &prevCode);
    assert(strcmp(soundex, "J05") == 0);
}

void test_Characters_AppendsCorrectCode() {
    char soundex[5] = "J";
    char prevCode = 'J';
    Characters('a', soundex, &prevCode);
   
