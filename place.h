#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
// TODO
//template <class T>
class placeInterface : virtual public sc_interface { //inherits from sc_interface
    public:
    virtual void addTokens() = 0; // =0 means pure specifier
    virtual void removeTokens() = 0;
    virtual bool testTokens() = 0;
};

// Place Channel:
// TODO
template<unsigned int Win = 1, unsigned int Wout = 1>
class place : public placeInterface {
    private:
    unsigned int tokens;

    public:
    place(unsigned int numOfTokens) : tokens(numOfTokens)
    {
    }

     /*void addTokens(unsigned int n) {
        tokens += n;
    } */

    void addTokens() {
        tokens += Win;
    }
     /*void removeTokens(unsigned int n) {
        tokens -= n;
    } */
    void removeTokens() {
        tokens -= Wout;
    }

     /*unsigned int testTokens() {
        return tokens;
    } */

    bool testTokens() {
        return tokens >= Wout;
    }
};

#endif // PLACE_H