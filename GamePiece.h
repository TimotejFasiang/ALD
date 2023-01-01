#ifndef ALDFINAL_GAMEPIECE_H
#define ALDFINAL_GAMEPIECE_H
#include <string>
#include <intrin.h>
using namespace std;

class GamePiece{
public:
    std::string name;
    bool up = false;
    bool right = false;
    bool down = false;
    bool left = false;
};

int randomNum(int rangeEnd){
    unsigned __int64 random;
    random = __rdtsc();
    do
        random=(int)rand()%(rangeEnd+1);
    while (random < 1);

    //printf("%d %d \n",rangeEnd, (int)random);
    return (int)random;
}

#endif //ALDFINAL_GAMEPIECE_H