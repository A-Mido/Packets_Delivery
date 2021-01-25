#ifndef QUEUE_H
#define QUEUE_H

class PriorityQueue{

    public:

    int max;
    int *nodes;

    PriorityQueue(int size){
        max = size + 1;
        nodes = new int[max];
        // initialize all array queue to -1
        for (int i = 0; i < max; i++)
            nodes[i] = -1;
    }

    int enqueue(int value){
        if (nodes[value] != -1)
            return 1;
        nodes[value] = value;
        return 0;    
    }

    void printQueue(int start, int window){


    }

    int bufferSearch(){
        
        return 0;
    }


    
};

#endif