#include "cut.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int digitValue(char);
long int RomToDec(char roman_Number[10]);
char * dec2romanstr(int num);
char * addRn(char Number1[10], char Number2[10]);
char * subRn(char Number1[10], char Number2[10]);
int TestRn(char Number[10]);

void __CUT_BRINGUP__Pass( void )
{

}

void __CUT__TestA( void ) //AddTwoRomanNumeralsTest
{
	ASSERT(strcmp(addRn("I", "III"),"IV") == 0, "Successful Test" );
	ASSERT(strcmp(addRn("XI", "XX"),"XXXI") == 0, "Successful Test" );
	ASSERT(strcmp(addRn("XM", "VX"),"CMXCV") == 0, "Successful Test" );
	ASSERT(strcmp(addRn("MM", "DCX"),"MMDCX") == 0, "Successful Test" );

}

void __CUT__TestB( void ) //SubtractTwoRomanNumeralsTest
{
	ASSERT(strcmp(subRn("III", "I"),"II") == 0, "Successful Test" );
	ASSERT(strcmp(subRn("XX", "XI"),"IX") == 0, "Successful Test" );
	ASSERT(strcmp(subRn("XM", "VX"),"CMLXXXV") == 0, "Successful Test" );
	ASSERT(strcmp(subRn("MM", "DCX"),"MCCCXC") == 0, "Successful Test" );

}

void __CUT__TestC( void ) //CheckIfLettersAreRomanNumeralTest
{
	ASSERT(1 == TestRn("IV"), "Successful Test" );
	ASSERT(1 == TestRn("XI"), "Successful Test" );
//	ASSERT(0 == TestRn("ABC"), "Successful Test" );
//	ASSERT(0 == TestRn("123"), "Successful Test" );
//	ASSERT(0 == TestRn("$#%&"), "Successful Test" );

}

void __CUT__TestD( void ) //CheckIfTheResultIsEqualOrLessThanZeroTest
{
//	ASSERT(strcmp(subRn("IV", "IV"),"Overflow") == 0, "Successful Test" );
//	ASSERT(strcmp(subRn("I", "III"),"Overflow") == 0, "Successful Test" );
}

void __CUT_TAKEDOWN__Pass( void )
{

}




////////////////////////////////////////////////
char * addRn(char Number1[10], char Number2[10])
{
	long int DecNumber1;
    long int DecNumber2;
	long int ReDec;
	char * ReChar;
    DecNumber1=RomToDec(Number1);
	DecNumber2=RomToDec(Number2);
    // addition
    ReDec=DecNumber1+DecNumber2;
	ReChar=dec2romanstr(ReDec);
	return ReChar;
}
/////////////////////////////////////////////
/////////////////////////////////////////////
char * subRn(char Number1[10], char Number2[10])
{
	long int DecNumber1;
	long int DecNumber2;
	long int ReDec;
	char * ReChar;
	DecNumber1=RomToDec(Number1);
	DecNumber2=RomToDec(Number2);
	// subtraction
	ReDec=DecNumber1-DecNumber2;
	if((ReDec) <=0)
	   {
	    puts("Roman Numerals cannot express zero or negative numbers.");
	    return "Overflow";
	   }
	else
	   {
	    ReChar=dec2romanstr(ReDec);
		return ReChar;
	   }
}
/////////////////////////////////////////////

/////////////////////////////////////////////
int TestRn(char Number[10])
{
	long int DecNumber;
	DecNumber=RomToDec(Number);
	if (DecNumber==0)
	 {
	  return 0;
	 }
	  else
	 {
	  return 1;
	 }
}
/////////////////////////////////////////////


////////////////////////////////////////
char * dec2romanstr(int num){
    int del[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1}; // Key value in Roman counting
    char * sym[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    char *rn = malloc(64);
    char res[64] = "\0";         //result string
    int i = 0;                   //
    while (num){                 //while input number is not zero
        while (num/del[i]){      //while a number contains the largest key value possible
            strcat(res, sym[i]); //append the symbol for this key value to res string
            num -= del[i];       //subtract the key value from number
        }
        i++;                     //proceed to the next key value
    }
    rn=res;
    return rn;
}

////////////////////////////////////////

///////////////////////////////////////
int digitValue(char c){

    int value=0;

    switch(c){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1;
    }

    return value;
}
////////////////////////////////////////

///////////////////////////////////////
long int RomToDec(char roman_Number[10]){

	    int i=0;
	    long int number =0;

	    while(roman_Number[i]){

	         if(digitValue(roman_Number[i]) < 0){
	             printf("Invalid roman digit : %c",roman_Number[i]);
	             return 0;
	         }

	         if((strlen(roman_Number) -i) > 2){
	             if(digitValue(roman_Number[i]) < digitValue(roman_Number[i+2])){
	                 printf("Invalid roman number");
	                 return 0;
	             }
	         }

	         if(digitValue(roman_Number[i]) >= digitValue(roman_Number[i+1]))
	             number = number + digitValue(roman_Number[i]);
	         else{
	             number = number + (digitValue(roman_Number[i+1]) - digitValue(roman_Number[i]));
	             i++;
	         }
	         i++;
	    }

    return number;
}
////////////////////////////////////////

