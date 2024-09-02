#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTests, GenerateSoundex_EmptyString_ReturnsEmptyString) {
    char input[] = "";
    char result[5] = {0};
    GenerateSoundex(input, result);
    ASSERT_STREQ("", result);
}

TEST(SoundexTests, GenerateSoundex_SingleCharacter_ReturnsPaddedCode) {
    char input[] = "A";
    char result[5] = {0};
    GenerateSoundex(input, result);
    ASSERT_STREQ("A000", result);
}

TEST(SoundexTests, GenerateSoundex_ValidName_ReturnsCorrectSoundex) {
    char input[] = "Jack";
    char result[5] = {0};
    GenerateSoundex(input, result);
    ASSERT_STREQ("J200", result);  // Expected Soundex for "Jack" is J200
}

TEST(SoundexTests, GenerateSoundex_LongString_ReturnsTruncatedCode) {
    char input[] = "JackandJill";
    char result[5] = {0};
    GenerateSoundex(input, result);
    ASSERT_STREQ("J253", result);  // Expected Soundex for "JackandJill" is J253
}

TEST(SoundexTests, GenerateSoundex_NumbersInString_ReturnsCorrectSoundex) {
    char input[] = "Jack123";
    char result[5] = {0};
    GenerateSoundex(input, result);
    ASSERT_STREQ("J200", result);  // Expected Soundex for "Jack123" is J200
}

TEST(SoundexTests, InitializeTheSoundex_ValidName_ReturnsInitializedSoundex) {
    char input[] = "John";
    char result[2] = {0};
    InitializeTheSoundex(input, result);
    ASSERT_STREQ("J", result);
}

TEST(SoundexTests, AppendingSoundexCharacters_ProcessesCharactersCorrectly) {
    char input[] = "John";
    char soundex[5] = "J";
    char prevCode = GetSoundexCode('J');
    AppendingSoundexCharacters(input, soundex, &prevCode);
    ASSERT_STREQ("J500", soundex);  // Expected Soundex result after appending
}

TEST(SoundexTests, Characters_AppendsCorrectCode) {
    char soundex[5] = "J";
    char prevCode = GetSoundexCode('J');
    Characters('o', soundex, &prevCode);  // 'o' is a vowel and should not append a number
    ASSERT_STREQ("J", soundex);
}

TEST(SoundexTests, AppendCode_ReturnsTrueForDifferentCode) {
    char code = '1';
    char prevCode = '0';
    bool result = AppendCode(code, prevCode);
    ASSERT_TRUE(result);
}

TEST(SoundexTests, AppendCode_ReturnsFalseForSameCode) {
    char code = '1';
    char prevCode = '1';
    bool result = AppendCode(code, prevCode);
    ASSERT_FALSE(result);
}

TEST(SoundexTests, SoundexCode_AppendsZerosToMatchMaxLength) {
    char soundex[5] = "J";
    SoundexCode(soundex);
    ASSERT_STREQ("J000", soundex);
}

TEST(SoundexTests, GetSoundexCode_ValidCharacter_ReturnsCorrectCode) {
    char character = 'B';
    char result = GetSoundexCode(character);
    ASSERT_EQ('1', result);
}

TEST(SoundexTests, GetSoundexCode_UnknownCharacter_ReturnsZero) {
    char character = 'X';
    char result = GetSoundexCode(character);
    ASSERT_EQ('2', result);  // X maps to 2 in the Soundex algorithm
}

TEST(SoundexTests, GenerateSoundex_CaseInsensitivity_ReturnsSameCode) {
    char inputLowercase[] = "jack";
    char inputUppercase[] = "JACK";
    char resultLowercase[5] = {0};
    char resultUppercase[5] = {0};
    GenerateSoundex(inputLowercase, resultLowercase);
    GenerateSoundex(inputUppercase, resultUppercase);
    ASSERT_STREQ(resultLowercase, resultUppercase);
}

TEST(SoundexTests, GenerateSoundex_SingleLetterWithDifferentCases_ReturnsPaddedCode) {
    char inputLowercase[] = "a";
    char inputUppercase[] = "A";
    char resultLowercase[5] = {0};
    char resultUppercase[5] = {0};
    GenerateSoundex(inputLowercase, resultLowercase);
    GenerateSoundex(inputUppercase, resultUppercase);
    ASSERT_STREQ(resultLowercase, resultUppercase);
    ASSERT_STREQ("A000", resultLowercase);
}

TEST(SoundexTests, HandlesEmptyString) {
    char result[5] = {0};
    GenerateSoundex("", result);
    ASSERT_STREQ("", result);
}

TEST(SoundexTests, HandlesSingleCharacter) {
    char result[5] = {0};
    GenerateSoundex("A", result);
    ASSERT_STREQ("A000", result);
}
