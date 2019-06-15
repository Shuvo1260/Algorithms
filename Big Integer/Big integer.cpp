#include<bits/stdc++.h>

using namespace std;

class BigInteger
{
private:
    char data[10000];
    int max_range;
    int len;
    bool sign_flag;
    BigInteger add(BigInteger number);              /// Add function()
    BigInteger subtract(BigInteger number);         /// Subtract function
    BigInteger multiply(BigInteger number);         /// Multiply function
    BigInteger divide(BigInteger number);           /// Divide function

public:

    BigInteger()                                    ///Normal initialization
    {
        max_range = 10000;
        len = 0;
        data[0] = '0';
        sign_flag = true;
    }
    BigInteger(int value)                           /// this is for declaration time such as int a = 2;
    {
        max_range = 10000;
        char temp[max_range];
        int index = 0;
        if(value == 0)
        {
            data[index++] = '0';
            len = index;
            data[len] = '\0';
        }
        else
        {
            while(value)
            {
                temp[index++] = (value % 10) + '0';
                value /= 10;
            }

            len = index;
            for(index = 0; index < len; index++)
                data[index] = temp[len - index - 1];
            data[len] = '\0';
        }

    }

    int Size()
    {
        return len;
    }

    void input()
    {
        scanf("%s", data);
        len = strlen(data);
        int temp_index = 0;
        while(data[temp_index] == '0'&& temp_index < len-1)
            temp_index++;
        int index;
        for(index = 0; temp_index < len; index++)
            data[index] = data[temp_index++];
        data[index] = '\0';

    }
    void output()
    {
        printf("%s", data);
    }

    BigInteger operator +(BigInteger number);       /// Adding two big integer()
    BigInteger operator -(BigInteger number);       /// Subtracting two big integer
    BigInteger operator *(BigInteger number);       /// Multiplying two big integer
    BigInteger operator /(BigInteger number);       /// Dividing two big integer
    BigInteger operator ++();                       /// Increment of big integer prefix()
    BigInteger operator --();                       /// Decrement of big integer prefix
    BigInteger operator ++(int Empty);              /// Increment of big integer postfix()
    BigInteger operator --(int Empty);              /// Decrement of big integer postfix

    BigInteger operator +(int number);              /// Adding a integer value with Big integer()
    BigInteger operator -(int number);              /// Subtracting a integer value with Big integer
    BigInteger operator *(int number);              /// Multiplying a integer value with Big integer
    BigInteger operator /(int number);              /// Dividing a integer value with Big integer

    BigInteger operator +=(int number);             /// Incrementing a certain value with Big integer()
    BigInteger operator -=(int number);             /// Subtracting a certain value with Big integer
    BigInteger operator *=(int number);             /// Multiplying a certain value with Big integer
    BigInteger operator /=(int number);             /// Dividing a certain value with Big integer

    BigInteger operator =(int value);               /// Integer copy()
    BigInteger operator =(BigInteger number);       /// Copy data()

    bool operator ==(BigInteger number);            /// Checking equality()
    bool operator !=(BigInteger number);            /// Checking not equality()
    bool operator <=(BigInteger number);            /// Checking less than equal
    bool operator >=(BigInteger number);            /// Checking greater than and equal
    bool operator <(BigInteger number);             /// Checking less than
    bool operator >(BigInteger number);             /// Checking greater than

    bool operator ==(int value);            /// Checking equality()
    bool operator !=(int value);            /// Checking not equality()
    bool operator <=(int value);            /// Checking less than equal
    bool operator >=(int value);            /// Checking greater than and equal
    bool operator <(int value);             /// Checking less than
    bool operator >(int value);             /// Checking greater than

    void Reverse();                                 /// Reverse the value()
};

/// Add function
BigInteger BigInteger :: add(BigInteger number)
{
    BigInteger result;
    int first[max_range];
    int second[max_range];

    for(int index = 0; index < len; index++)
        first[index] = data[len-index-1] - '0';
    int first_len = len;

    for(int index = 0; index < number.Size(); index++)
        second[index] = number.data[number.len-index-1] - '0';
    int second_len = number.len;

    int carry = 0;
    int addition_len = min(first_len, second_len);
    int sum;

    for(int index = 0; index < addition_len; index++)
    {
        sum = first[index] + second[index] + carry;
        result.data[index] = sum % 10 + '0';
        carry = sum / 10;
    }
    for(int index = addition_len; index < first_len; index++)
    {
        sum = first[index] + carry;
        result.data[index] = sum % 10 + '0';
        carry = sum / 10;
    }

    for(int index = addition_len; index < second_len; index++)
    {
        sum = second[index] + carry;
        result.data[index] = sum % 10 + '0';
        carry = sum / 10;
    }
    result.len = max(first_len,second_len);
    if(carry)
        result.data[result.len++] = carry + '0';
    while(result.data[result.len-1] == '0'&& result.len > 1)
        result.len--;

    result.data[result.len] = '\0';
    result.Reverse();
    return result;
}

/// Copy data
BigInteger BigInteger :: operator =(BigInteger number)
{
    len = number.Size();

    for(int index = 0; index <= len/2; index++)
    {
        data[index] = number.data[index];
        data[len-index-1] = number.data[len-index-1];
    }
}

/// Integer copy
BigInteger BigInteger :: operator =(int value)
{
    max_range = 10000;
    char temp[max_range];
    int index = 0;
    while(value)
    {
        temp[index++] = (value % 10) + '0';
        value /= 10;
    }

    len = index;

    for(index = 0; index < len; index++)
        data[index] = temp[len - index - 1];
    data[len] = '\0';
}

///Add operation two big integer
BigInteger BigInteger :: operator +(BigInteger number)
{
    return add(number);
}

/// Adding a integer value with Big integer
BigInteger BigInteger :: operator +(int number)
{
    BigInteger temp = number;
    temp = add(temp);
    for(int index = 0; index < temp.Size(); index++)
        data[index] = temp.data[index];
    len = temp.Size();
    data[len] = '\0';
    return temp;
}

/// Incrementing a certain value with Big integer
BigInteger BigInteger :: operator +=(int number)
{
    BigInteger temp = number;
    temp = add(temp);
    for(int index = 0; index < temp.Size(); index++)
        data[index] = temp.data[index];
    len = temp.Size();
    data[len] = '\0';
    return temp;
}

/// Increment of big integer prefix
BigInteger BigInteger :: operator ++()
{
    BigInteger number = 1;
    number = add(number);
    for(int index = 0; index < number.Size(); index++)
        data[index] = number.data[index];
    len = number.Size();
    data[len] = '\0';
    return number;
}

/// Increment of big integer postfix
BigInteger BigInteger :: operator ++(int Empty)
{
    BigInteger number = 1;
    number = add(number);
    for(int index = 0; index < number.Size(); index++)
        data[index] = number.data[index];
    len = number.Size();
    data[len] = '\0';
    return number;
}

/// Reversing function of a big integer
void BigInteger :: Reverse()
{
    char temp[max_range];

    for(int index = 0; index < len; index++)
        temp[index] = data[len - index - 1];
    for(int index = 0; index <= len/2; index++)
    {
        data[index] = temp[index];
        data[len - index - 1] = temp[len - index - 1];
    }
}

/// Checking equality
bool BigInteger :: operator ==(BigInteger number)
{
    int temp1;
    int temp2;
    sscanf(data,"%d", &temp1);
    sscanf(number.data,"%d", &temp2);
    if(!temp1 && !temp2)
        return true;
    if(len != number.len)
        return false;
    for(int index = 0; index < len; index++)
        if(data[index] != number.data[index])
            return false;
    return true;
}
/// Checking not equality
bool BigInteger :: operator !=(BigInteger number)
{
    int temp1;
    int temp2;
    sscanf(data,"%d", &temp1);
    sscanf(number.data,"%d", &temp2);
    if(!temp1 && !temp2)
        return false;
    if(len != number.len)
        return true;
    for(int index = 0; index < len; index++)
        if(data[index] != number.data[index])
            return true;
    return false;
}

/// Checking less than equal
bool BigInteger :: operator <=(int value)
{//cout << data << " " << value << endl;
    BigInteger number = value;
//printf("%d\n", strcmp(data,number.data));


    return false;
}

/// Checking greater than and equal
bool BigInteger :: operator >=(int value)
{
    //
}

/// Checking less than
bool BigInteger :: operator <(int value)
{
    //
}

/// Checking greater than
bool BigInteger :: operator >(int value)
{
    //
}

int main()
{
    int index = 0;
    for(BigInteger counter = 1; counter <= 100; counter++)
    {
        counter.output();
        cout << endl;
    }

//    BigInteger c = 123;
//    BigInteger a ;
//    a.input();
//    c = a += 10;
//    a += 20;
//    c.output();
//    c.input();
//    BigInteger d;
//
//    if(a != c)
//        printf("Not same!\n");
//
//
//    d = a + c;
//    d.output();
//    cout << endl;


    return 0;
}
