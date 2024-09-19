#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 //ASSERT_EQ(soundex,"A200");
  generateSoundex("AT", soundex);
 //ASSERT_EQ(soundex,"A300");
   generateSoundex("BR", soundex);
 //ASSERT_EQ(soundex,"B600");
   generateSoundex("CMXT", soundex);
 //ASSERT_EQ(soundex,"B523");
  generateSoundex("GCDL", soundex);
 //ASSERT_EQ(soundex,"C234");
  generateSoundex("ALRN", soundex);
 //ASSERT_EQ(soundex,"A465");
 generateSoundex("ALRU", soundex);
 //ASSERT_EQ(soundex,"A460");
 generateSoundex("BE", soundex);
 //ASSERT_EQ(soundex,"B000");
 generateSoundex("CI", soundex);
 //ASSERT_EQ(soundex,"C000");
 generateSoundex("DF", soundex);
 //ASSERT_EQ(soundex,"D100");
 generateSoundex("F0", soundex);
 //ASSERT_EQ(soundex,"F000");
 generateSoundex("BFP", soundex);
 //ASSERT_EQ(soundex,"B110");
 generateSoundex("", soundex);
 //ASSERT_EQ(soundex,"");
}
