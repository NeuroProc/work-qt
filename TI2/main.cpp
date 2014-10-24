#include <stdio.h>
#include <iostream>
#include <string.h>

/* VARIANT 3 */

using namespace std;

u_long LFSR(FILE *C, FILE *M, FILE *Kf);
u_long GEFFE(FILE *C, FILE *M, FILE *Kf);
u_long RC4(FILE *C, FILE *M, FILE *Kf);
void swapChar(char &, char &);

int main(int argc, char *argv[])
{

    if( argc < 4 )
    {
        cout << "incorrect data" << endl;
        return -1;
    }

    FILE *C, *M, *K;
    M = fopen(argv[1], "r");
    C = fopen(argv[2], "w");
    K = fopen(argv[3], "w");

    int numb;
    std::bitset<sizeof(u_long) * 8> endState;

    cout << "1 - LFSR" << endl << "2 - GEFFE" << endl << "3 - RC4"  << endl <<  "Enter crypto algorithm: ";
    cin >> numb;

    switch (numb)
    {
    case 1:
        endState = LFSR(C, M, K);
        break;
    case 2:
        endState = GEFFE(C, M, K);
        break;
    case 3:
        endState = RC4(C, M, K);
        break;
    default:
        break;
    }

    //std::bitset<sizeof(u_long) * 8> key(LSFSR(C, M));
    //fprintf(K, "%s\n", endState.to_string().data());

    fclose(C);
    fclose(M);
    fclose(K);

    return 0;
}

u_long LFSR(FILE *C, FILE *M, FILE *Kf)
{
    char K;
    u_long x25, x3, x0;
    // x - члены многочлена для вставки первого чимвола
    x25 = ((u_long)1) << 24;
    x3 = ((u_long)1) << 2;
    x0 = (u_long) 1;
    u_long longK;
    u_long mask25 = 0;//25 - битовая маска (cдвиговый регистр, длина которого равна степени многочлена)
    for( int i = 0; i < 25; i++ )
    {
        mask25 = mask25 | x0;
        x0 = x0 << 1;
    }
    x0 = (u_long) 1;

    std::bitset<25> key;
    cout << "Enter start register: ";
    cin >> key;

    cout << "U REG: " << key << endl;
    longK = key.to_ulong();
    K = (char)(longK >> 17);

    std::bitset<8> keyBin;

    char inputsymbol = fgetc(M);
    while( !feof(M) )
    {
        char outputsymbol = K ^ inputsymbol;
        fputc(outputsymbol, C );

        keyBin = K;
        fprintf(Kf, "%s ", keyBin.to_string().c_str());

//        cout << keyBin << endl;

        for (int i = 0; i < 8; i++)
        {
            u_long temp = 0;
            if( longK & x25 )
                temp = temp ^ (u_long)1;
            if( longK & x3 )
                temp = temp ^ (u_long)1;

            longK = (longK << 1) & mask25;
            longK = longK | temp;

        }
        K = (char)(longK >> 17);

        inputsymbol = fgetc(M);
    }
    return (u_long)K;
}

u_long GEFFE(FILE *C, FILE *M, FILE *Kf)
{
    char Kg;
    u_long x25, x3, x0, x33, x13, x23, x5;

    x25 = ((u_long)1) << 24;
    x3 = ((u_long)1) << 2;

    x33 = ((u_long)1) << 32;
    x13= ((u_long)1) << 12;

    x23 = ((u_long)1) << 22;
    x5 = ((u_long)1) << 4;

    u_long longK1, longK2, longK3;
    u_long mask25 = 0, mask33 = 0, mask23 = 0;//23, 31, 39 - битовая маска

    x0 = (u_long)1;
    for( int i = 0; i < 25; i++ )
    {
     mask25 = mask25 | x0;
     x0 = x0 << 1;
    }
    x0 = (u_long)1;
    for( int i = 0; i < 33; i++ )
    {
     mask33 = mask33 | x0;
     x0 = x0 << 1;
    }
    x0 = (u_long)1;
    for( int i = 0; i < 23; i++ )
    {
     mask23 = mask23 | x0;
     x0 = x0 << 1;
    }
    x0 = (u_long)1;

    std::bitset<25> key1;
    std::bitset<33> key2;
    std::bitset<23> key3;

    cout << "Enter start register N1: ";
    cin >> key1;
    cout << "Enter start register N2: ";
    cin >> key2;
    cout << "Enter start register N3: ";
    cin >> key3;

    cout << "U REG1: " << key1 << endl;
    cout << "U REG2: " << key2 << endl;
    cout << "U REG3: " << key3 << endl;

    longK1 = key1.to_ulong();
    longK2 = key2.to_ulong();
    longK3 = key3.to_ulong();


    char inputsymbol = fgetc(M);
    Kg = (char)(( (longK1 >> 17) & (longK2 >> 25) ) | ( ~(longK1 >> 17) & (longK3 >> 15) ));

    std::bitset<8> keyBin;

    while( !feof(M) )
    {
        fputc( (Kg ^ inputsymbol), C );

        keyBin = Kg;
        fprintf(Kf, "%s ", keyBin.to_string().c_str());

//        cout << keyBin << endl;

        for (int i = 0; i < 8; i++)
        {
            u_long temp = 0;
            if( longK1 & x25 )
                temp = temp ^ (u_long)1;
            if( longK1 & x3 )
                temp = temp ^ (u_long)1;
            longK1 = (longK1 << 1) & mask25;
            longK1 = longK1 | temp;

/*
            std::bitset<64> tst;
            tst = longK2;
            cout << "DEBUG: " << tst << endl;
*/

            temp = 0;
            if( longK2 & x33 )
                temp = temp ^ (u_long)1;
            if( longK2 & x13 )
                temp = temp ^ (u_long)1;
            longK2 = (longK2 << 1) & mask33;
            longK2 = longK2 | temp;
/*
            tst = mask33;
            cout << "DEBUG: " << tst << endl;
*/

            temp = 0;
            if( longK3 & x23 )
                temp = temp ^ (u_long)1;
            if( longK3 & x5 )
                temp = temp ^ (u_long)1;
            longK3 = (longK3 << 1) & mask23;
            longK3 = longK3 | temp;


            std::bitset<64> key;
            key = longK1 >> 8;
            cout << "longK1[" << i << "]: " << key << endl;
            key = longK2 >> 8;
            cout << "longK2[" << i << "]: " << key << endl;
            key = longK3 >> 8;
            cout << "longK3[" << i << "]: " << key << endl << endl;


        }

        Kg = (char)(( (longK1 >> 17) & (longK2 >> 25) ) | ( ~(longK1 >> 17) & (longK3 >> 15) ));

        inputsymbol = fgetc(M);
    }
    return (u_long)Kg;
}

u_long RC4(FILE *C, FILE *M, FILE *Kf)
{
    //char userkey[100];
    string userkey;
    char Sbox[256];
    int count = 0;

    int symbCount;
    cout << "Enter count symbols: ";
    cin >> symbCount;

    cout << "Enter key: ";
    for (int i = 0; i < symbCount; i++)
    {
        int symb;
        cin >> symb;
        userkey += (char)symb;
    }
    //cout << userkey << endl;

    //cin >> userkey;

    for( int i= 0; i < 256; i++ )
         Sbox[i] = i;
    int j = 0;
    for( int i = 0; i < 256; i++)
    {
         //j = (j + (unsigned char)Sbox[i] + userkey[i % strlen(userkey.c_str())]) % 256;
         j = (j + (unsigned char)Sbox[i] + userkey[i % symbCount]) % 256;
         swapChar( Sbox[i], Sbox[j] );
    }

    int i = 0;
    j = 0;
    char currentKey;

    char symbol = fgetc(M);
    while (!feof(M))
    {
        count++;

        i = (i+1) % 256;
        j = (j+(unsigned char)Sbox[i]) % 256;
        swapChar(Sbox[i], Sbox[j]);
        currentKey = Sbox[ ( (unsigned char)Sbox[i] + (unsigned char)Sbox[j] ) % 256 ];

        char newsym = (currentKey ^ symbol);

        fputc(newsym, C);
        fprintf(Kf, "%d ", (int)((unsigned char)currentKey));

        symbol = fgetc(M);
    }
    cout << count << endl;

    return count;

}

void swapChar( char &a, char &b )
{
     char h = a;
     a = b;
     b = h;
}

