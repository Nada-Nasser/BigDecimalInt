#include "BigDecimalInt.h"


/// Constructors :-
///----------------
// default constructor that make the number = 0
BigDecimalInt::BigDecimalInt()
{}

// Initialize from string and store it in a string
BigDecimalInt::BigDecimalInt (string decStr) // Initialize from string
{
    BigNumber = decStr;
    if(decStr[0] == '+')
        BigNumber.erase(0,1);

    if(decStr[0] == '-')
    {
        BigNumber.erase(0,1);
        sign += decStr[0];
    }
    BigNumber = RemoveZeros(BigNumber);
    NumberSize = BigNumber.size();
}

// Initialize from integer and store it in a string
BigDecimalInt::BigDecimalInt (int decInt)    // Initialize from integer
{
    BigNumber = to_string(decInt);
    if(BigNumber[0] == '+')
        BigNumber.erase(0,1);

    if(BigNumber[0] == '-')
    {
        sign += BigNumber[0];
        BigNumber.erase(0,1);

    }
    BigNumber = RemoveZeros(BigNumber);
    NumberSize = BigNumber.size();

}
///_________________________________________________________________________________

/// Friend functions:-
///--------------------

//to take the bigNumber from the user directly
ostream& operator << (ostream& out, BigDecimalInt number)
{

    out << number.sign << number.BigNumber;
    return out;
}

///_________________________________________________________________________________

/// Public Functions :-
///---------------------

// take 2 objects , check the sign of the output and return the sum
BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt anotherDec)
{
    int sum = 0 , carry = 0;
    bool t = true;
    string result = "";

    int DiffSize = 0 ;//, Size1 = NumberSize , Size2 = anotherDec.NumberSize ;
    string bigger = BigNumber , smaller = anotherDec.BigNumber;
    BigDecimalInt obj;

    FindSmallerAndBigger(bigger,smaller,t);
    DiffSize = (bigger.size()) - (smaller.size());
    AddZeroes(DiffSize , smaller);

//******************* Checking the sign ****************************//

        if(sign == "\0" && anotherDec.sign == "-")
        {
            obj.BigNumber = anotherDec.BigNumber;
            obj.sign = "\0";
            return obj = *this - obj;
        }
        else if(sign == "-" && anotherDec.sign == "\0")
        {
            obj.BigNumber = BigNumber;
            obj.sign = "\0";
            return obj = anotherDec - obj ;
        }

// ***************here the Addition begins****************//

    for(int i = bigger.size()-1 ; i >=0  ; i--)
    {
        int term1=0 , term2=0 ;
        term1 = bigger[i] - '0' ;
        term2 = smaller[i] -'0';

        sum = carry + term1 + term2;
        if(sum > 9) {
            carry = 1;
            sum -= 10;
        }
        else{
            carry = 0;
        }

        result.insert(0,to_string(sum));
    }

    if(carry != 0)
    {
        string one = "1";
        result.insert(0,one);
    }

    if(sign=="-")
        result.insert(0,"-");

    BigDecimalInt SUM(result);
    return SUM;
}
///--------------------------------------------------------------------------------

// take 2 objects , check the sign of the output and return the sub
BigDecimalInt BigDecimalInt:: operator- (BigDecimalInt anotherDec)
{
    bool isAssumpRight = true;
    string bigger = BigNumber , smaller = anotherDec.BigNumber;
    string result;
    int tempResult = 0 , temp = 0;
    BigDecimalInt obj;
//******************* Checking the sign ****************************//

    if(sign == "-" && anotherDec.sign == "-"){///-5--6 =-5+6
       smaller = BigNumber , bigger = anotherDec.BigNumber;
    }
    else if(sign == "\0" && anotherDec.sign == "-"){///5--6 = 5+6
        obj.sign = "\0";
        obj.BigNumber = anotherDec.BigNumber;
        return obj = *this + obj;
    }
    else if(sign == "-" && anotherDec.sign == "\0"){///-5-6 = -5 + -6
        obj.sign = "-";
        obj.BigNumber = anotherDec.BigNumber;
        return obj = *this + obj;
    }

// ***************here the subtraction begins****************\

    FindSmallerAndBigger(bigger , smaller , isAssumpRight);
    int DiffSize = (bigger.size()) - (smaller.size());
    AddZeroes(DiffSize , smaller);

    for(int i = smaller.size()-1 ; i >= 0 ; i--){
        if( (int)(bigger[i])  >= (int)(smaller[i]) ){
            tempResult = (int)(bigger[i]) - (int)(smaller[i]);
            result.insert(0,to_string(tempResult));///************ itos 3shan n7awel el rakam l string**********
        }
        else{
            temp =(int)(bigger[i - 1]) - 1;
            bigger[i-1] = ((char)(temp));

            tempResult = ((int)(bigger[i]) + 10) - (int)(smaller[i]);
            result.insert( 0 , to_string(tempResult));
        }
    }

    if(!isAssumpRight)
        result.insert(0 , "-");

    BigDecimalInt sub(result);
    return sub;
}

///---------------------------------------------------------------------------

/// Global Functions :-
///--------------------

// it add zeros at the end of the matrix to make the operations easier
void AddZeroes(int n , string& s)
{
    string zero = "0";
    for(int i = 0; i < n ;i++)
    {
        s.insert(0,zero);
    }
}
//  it add zeros at the end of the matrix to make the operations easier
string RemoveZeros(string strNum){
    while (strNum[0] == '0')//hysheel el zeros
        strNum.erase(0, 1);
    return strNum;
}
// To determine which number is bigger
// so that we can determine the output sign of the operators correctly
void FindSmallerAndBigger(string &bigger,string &smaller,bool &isAssumptionTrue){
    string temp;
    if(bigger.size() == smaller.size()){
		for (int i = 0; i < bigger.size(); i++) {
			if ((int)(bigger[i]) < (int)(smaller[i])){
                swap(bigger,smaller);
                isAssumptionTrue = false;
                break;
			}
        }
    }
    else if(bigger.size() < smaller.size()){
        swap(bigger,smaller);
        isAssumptionTrue = false;
    }
}

