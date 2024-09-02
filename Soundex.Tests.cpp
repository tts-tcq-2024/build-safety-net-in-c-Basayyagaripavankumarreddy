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
    char input[1] = "";
    char result[5];
    GenerateSoundex(input, result);
    assert(strcmp(result, "") == 0);
}

void test_GenerateSoundex_SingleCharacter_ReturnsPaddedCode() {
    char input[2] = "A";
    char result[5];
    GenerateSoundex(input, result);
    assert(strcmp(result, "A000") == 0);
}

void test_GenerateSoundex_ValidName_ReturnsCorrectSoundex() {
    char input[5] = "Jack";
    char result[5];
    GenerateSoundex(input, result);
    assert(strcmp(result, "J020") == 0);
}

void test_GenerateSoundex_LongString_ReturnsTruncatedCode() {
    char input[12] = "JackandJill";
    char result[5];
    GenerateSoundex(input, result);
    assert(strcmp(result, "J020") == 0);
}

void test_GenerateSoundex_NumbersInString_ReturnsCorrectSoundex() {
    char input[8] = "Jack123";
    char result[5];
    GenerateSoundex(input, result);
    assert(strcmp(result, "J020") == 0);
}

void test_InitializeTheSoundex_ValidName_ReturnsInitializedSoundex() {
    char input[5] = "John";
    char result[5] = "";
    InitializeTheSoundex(input, result);
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
    assert(strcmp(soundex, "J0") == 0);
}

void test_AppendCode_ReturnsTrueForDifferentCode() {
    assert(AppendCode('1', '0'));
}

void test_AppendCode_ReturnsFalseForSameCode() {
    assert(!AppendCode('1', '1'));
}

void test_SoundexCode_AppendsZerosToMatchMaxLength() {
    char soundex[5] = "J";
    SoundexCode(soundex);
    assert(strcmp(soundex, "J000") == 0);
}

void test_GetSoundexCode_ValidCharacter_ReturnsCorrectCode() {
    assert(GetSoundexCode('B') == '1');
}

void test_GetSoundexCode_UnknownCharacter_ReturnsZero() {
    assert(GetSoundexCode('X') == '2');
}

void test_GenerateSoundex_CaseInsensitivity_ReturnsSameCode() {
    char inputLowercase[5] = "jack";
    char inputUppercase[5] = "JACK";
    char resultLowercase[5];
    char resultUppercase[5];
    GenerateSoundex(inputLowercase, resultLowercase);
    GenerateSoundex(inputUppercase, resultUppercase);
    assert(strcmp(resultLowercase, resultUppercase) == 0);
}

void test_GenerateSoundex_SingleLetterWithDifferentCases_ReturnsPaddedCode() {
    char inputLowercase[2] = "a";
    char inputUppercase[2] = "A";
    char resultLowercase[5];
    char resultUppercase[5];
    GenerateSoundex(inputLowercase, resultLowercase);
    GenerateSoundex(inputUppercase, resultUppercase);
    assert(strcmp(resultLowercase, resultUppercase) == 0);
    assert(strcmp(resultLowercase, "A000") == 0);
}

void test_HandlesEmptyString() {
    assert(strcmp(GenerateSoundex(""), "") == 0);
}

void test_HandlesSingleCharacter() {
    assert(strcmp(GenerateSoundex("A"), "A000") == 0);
}

int main() {
    // Run tests
    test_GenerateSoundex_EmptyString_ReturnsEmptyString();
    test_GenerateSoundex_SingleCharacter_ReturnsPaddedCode();
    test_GenerateSoundex_ValidName_ReturnsCorrectSoundex();
    test_GenerateSoundex_LongString_ReturnsTruncatedCode();
    test_GenerateSoundex_NumbersInString_ReturnsCorrectSoundex();
    test_InitializeTheSoundex_ValidName_ReturnsInitializedSoundex();
    test_AppendingSoundexCharacters_ProcessesCharactersCorrectly();
    test_Characters_AppendsCorrectCode();
    test_AppendCode_ReturnsTrueForDifferentCode();
    test_AppendCode_ReturnsFalseForSameCode();
    test_SoundexCode_AppendsZerosToMatchMaxLength();
    test_GetSoundexCode_ValidCharacter_ReturnsCorrectCode();
    test_GetSoundexCode_UnknownCharacter_ReturnsZero();
    test_GenerateSoundex_CaseInsensitivity_ReturnsSameCode();
    test_GenerateSoundex_SingleLetterWithDifferentCases_ReturnsPaddedCode();
    test_HandlesEmptyString();
    test_HandlesSingleCharacter();

    printf("All tests passed!\n");
    return 0;
}
