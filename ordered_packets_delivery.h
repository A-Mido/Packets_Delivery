#ifndef QUEUE_H
#define QUEUE_H

class PriorityQueue{

    private:
    int max;
    int *nodes;

    int elementSearch(int start){
        for (int i = 0; i < max; i++){
            if (nodes[i] == start){
                cout << nodes[i] << " ";
                nodes[i] = -1;
                start = (start + 1) % max;
            }
        }
        return start;
    }

    public:

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
        // if the comming packet is in the window
        for (int i = 0; i < max; i++){
            if (nodes[i] != -1 && (nodes[i] + max <= start + window))
                nodes[i] += max + 1;
        }
        // ordering the queue
        for (int i = 0; i < max; i++){
            for (int j = 1; j < (max - 1); j++){
                if(nodes[j - 1] > nodes[j]){
                    int temp = nodes[j - 1];
                    nodes[j - 1] = nodes[j];
                    nodes[j] = temp;
                }
            }
        }
        // printing the array 
        for (int i = 0; i < max; i++){
            if (nodes[i] != -1)
                cout << nodes[i] % (max + 1) << " ";
        }

    }

    int bufferSearch(int start){
        start = elementSearch(start);
        if (start == 0)
            start = elementSearch(start);
        return start;
    }

    void freePriorityQueue(){
        delete[] nodes;
    }

    
};

#endif