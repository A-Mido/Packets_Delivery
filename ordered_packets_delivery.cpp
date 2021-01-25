#include <iostream>
#include <cmath>
#include <cstring>
#include <ctype.h>

using namespace std;
#include "ordered_packets_delivery.h"

int main(int argc, char* argv[])
{
    // defining properties
    int seqNumBits; // sequence number of bits
    int winSizeBits; // window size
    int initSeq; // initial sequence
    int maxNumber; // maximum number permitted
    int drop[100]; // array to drop failed elements
    int dropFlag = 0; // drop flag to follow elements
    int dropCounter = 0; // count dropped elements

    // flags to catch any kind of error
    int flagErrorArguments = 0; // if user enters wrong args
    int flagErrorPacketID = 0; // if the packet itself corrupted
    int flagErrorSeqNumBits = 0; 
    int flagErrorInitSeq = 0;
    int flagErrorWinSize = 0;

    for(int i = 0 ; i < 100 ; i++){
        drop[i] = -1;
    }

    // some error handling
    if (argc < 5)
        flagErrorArguments = 1;
    if (argc >= 2)
        seqNumBits = atoi(argv[1]);
    if (argc >= 3)
        winSizeBits = atoi(argv[2]);
    if (argc >= 4){
        initSeq = atoi(argv[3]);
        maxNumber = pow(2, seqNumBits) - 1;
    }
    if (argc >= 2){
        int length = strlen(argv[1]);
        for (int i = 0; i < length; i++){
            if (seqNumBits <= 0 || !isdigit(argv[1][i]))
                flagErrorWinSize = 1;
        }
    }
    if (argc >= 3){
        int length = strlen(argv[2]);
        for (int i = 0; i < length; i++){
            if (isdigit(argv[2][i]))
                flagErrorWinSize = 1;
        }
        if (flagErrorSeqNumBits == 0)
            if (winSizeBits <= 0 || winSizeBits > maxNumber)
                flagErrorWinSize = 1;
    }
    if (argc >= 4){
        int length = strlen(argv[3]);
        for (int i = 0; i < length; i++){
            if (isdigit(argv[3][i]))
                flagErrorInitSeq = 1;
        }
        if (flagErrorSeqNumBits == 0)
            if(initSeq < 0 || initSeq > maxNumber)
                flagErrorInitSeq = 1;
    }
    if (argc >= 5){
        for (int i = 0; i < argc; i++){
            int num = atoi(argv[i]);
            int length = strlen(argv[i]);
            for( int j = 0 ; j < length; j++){

                if(flagErrorSeqNumBits == 0)
                    if(num > maxNumber || num < 0)
                        flagErrorPacketID = 1;
            }

        }
    }


    if (flagErrorArguments || flagErrorPacketID || flagErrorSeqNumBits
        || flagErrorInitSeq || flagErrorWinSize){
            if (flagErrorArguments == 1)
                cout<<"Invalid number of arguments ";
            if (flagErrorPacketID == 1)
                "Invalid packet ID ";
            if (flagErrorSeqNumBits == 1)
                cout<<"Invalid seqNumBits ";
            if (flagErrorInitSeq == 1)
                cout<<"Invalid initSeq ";
            if (flagErrorWinSize == 1)
                cout<<"Invalid winSize ";
            
            return 0;
    }

    




    

    return 0;
}