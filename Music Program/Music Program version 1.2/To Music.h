#ifndef TO_MUSIC_H
#define TO_MUSIC_H
using namespace std;

class toMusic
{
protected:
    vector<string> line6; //9Z
    vector<string> line7; //J
    vector<string> line8; //VP
    vector<string> line9; //CY
    vector<string> line10; //M
    vector<string> line11; //WD
    vector<string> line12; //SN
    vector<string> line13; //OT
    vector<string> line14; //E
    vector<string> line15; //AH
    vector<string> line16; //RI
    vector<string> line17; //L
    vector<string> line18; //UG
    vector<string> line19; //FB
    vector<string> line20; //KQ
    vector<string> line21; //X
    vector<string> line22; //Spaces & Tabs

    vector<string> music; //place holder

public:
    void vectorToMusic(); //sorts vector into individual letters
    void transTextToNums(const char); //writes letter value to music
    void inputChoice(); //fills vector with data from document or from user
    void outputToScreen(); //outputs to screen
    void outputToFile(); //outputs to file
    void outputChoice(); //asks user how they want the output to be
    void fillLine(); //fills vectors with default values
    void treble(); //Adds treble cleft to the music
};

#endif
