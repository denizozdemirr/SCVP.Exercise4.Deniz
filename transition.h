#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
// TODO
template<unsigned int N = 1, unsigned int M = 1, unsigned int L = 0>
SC_MODULE(TRANSITION) {
    public:
    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;
    
    SC_CTOR(TRANSITION) {}



    //part1

   /* void fire () {
        unsigned int tokens = in-> testTokens();
        if (tokens > 0) {
            std::cout << this->name() << ": Fired" << std::endl;
            in  -> removeTokens(1);
            out -> addTokens(1);
        }
        else if (token == 0) {
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }

    } */

    //part2
    /*
     void fire() {
        unsigned int tokens = in->testTokens();
        if(tokens > 0) {
        bool haveTokens = true;
        for (int i = 0; i < N; i++) {
            if(in[i]->testTokens() == 0) {
                haveTokens = false;
                break;
            }
        }

        if(haveTokens) {
            for (int i = 0; i < N; i++) {
                in[i]->removeTokens(1);
            }

            for (int i = 0; i < M; i++) {
                out[i]->addTokens(1);
            }

            std::cout << this->name() << ": Fired" << std::endl;
            in->removeTokens(1);
            out->addTokens(1);
        } else if (tokens == 0) {
        } else {
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }

    }

    
    */

    void fire() { //fire() implemented in the SC_CTOR 
        bool haveTokens = true;
        for (int i = 0; i < N; i++) {
            if(!in[i]->testTokens()) {
                haveTokens = false;
                break;
            }
        }
         
        if (haveTokens) {
            for (int i = 0; i < L; i++) {
                if(inhibitors[i]->testTokens()) {
                    haveTokens = false;
                    break;
                }
            }
        }

        if(haveTokens) {
            for (int i = 0; i < N; i++) {
                in[i]->removeTokens();
            }
            
            for (int i = 0; i < M; i++) {
                out[i]->addTokens();
            }

            std::cout << this->name() << ": Fired" << std::endl;
        } else {
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }
        
    }
};

#endif // TRANSITION_H