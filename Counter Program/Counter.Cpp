//This program takes an input, counts the amount of each letter,
//and outputs a Numerical value for the times each ltter was used
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class translate
{
protected:
    int a, b, c, d, e, f, g, h, i, j, k, l, m;
    int n, o, p, q, r, s, t, u, v, w, x, y, z;
    int one, two, three, four, five, six, seven, eight, nine, zero;
    int space;
    int misc = 0;

public:
    void Set();
    void textToVector();
    void DataSort(const vector<string>&);
    void countChars(char);
    void Output();
};

void translate::Set()
{
    a =0;
    b =0;
    c =0;
    d =0;
    e =0;
    f =0;
    g =0;
    h =0;
    i =0;
    j =0;
    k =0;
    l =0;
    m =0;
    n =0;
    o =0;
    p =0;
    q =0;
    r =0;
    s =0;
    t =0;
    u =0;
    v =0;
    w =0;
    x =0;
    y =0;
    z =0;
    one =0;
    two =0;
    three =0;
    four =0;
    five =0;
    six =0;
    seven =0;
    eight =0;
    nine =0;
    zero =0;
    space = 0;
    misc = 0;
}

void translate::textToVector()
{
    Set();
    vector<string> data;
    string text;
    ifstream input;

    input.open("text.txt");

    input >> text;
    data.push_back(text);

    while(!input.eof())
    {
      input >> text;
      data.push_back(text);
    }

    input.close();

    DataSort(data);

}

void translate::DataSort(const vector<string>& data)
{
    int max = data.size();
    string word;

    for (int i = 0; i<max ; i++)
    {
        word = data[i];

        for (int j = 0; j< word.size() ; j++)
        {

            countChars(word[j]);

        }
    }
    Output();
}


//you're an idiot BTW, could have made an array with 26+extra values rather than using individual integers
void translate::countChars(char letter)
{
    tolower(letter);

  switch (letter)
    {
        case 'a': a++;
          break;
        case 'b': b++;
          break;
        case 'c': c++;
          break;
        case 'd': d++;
          break;
        case 'e': e++;
          break;
        case 'f': f++;
          break;
        case 'g': g++;
          break;
        case 'h': h++;
          break;
        case 'i': i++;
          break;
        case 'j': j++;
          break;
        case 'k': k++;
          break;
        case 'l': l++;
          break;
        case 'm': m++;
          break;
        case 'n': n++;
          break;
        case 'o': o++;
          break;
        case 'p': p++;
          break;
        case 'q': q++;
          break;
        case 'r': r++;
          break;
        case 's': s++;
          break;
        case 't': t++;
          break;
        case 'u': u++;
          break;
        case 'v': v++;
          break;
        case 'w': w++;
          break;
        case 'x': x++;
          break;
        case 'y': y++;
          break;
        case 'z': z++;
          break;
        case '1': one++;
          break;
        case '2': two++;
          break;
        case '3': three++;
          break;
        case '4': four++;
          break;
        case '5': five++;
          break;
        case '6': six++;
          break;
        case '7': seven++;
          break;
        case '8': eight++;
          break;
        case '9': nine++;
          break;
        case '0': zero++;
          break;
        case ' ': space++;
          break;
        default :
            cout << letter;

    }
}

void translate::Output()
{
    cout << "a \t" << a << endl;
    cout << "b \t" << b << endl;
    cout << "c \t" << c << endl;
    cout << "d \t" << d << endl;
    cout << "e \t" << e << endl;
    cout << "f \t" << f << endl;
    cout << "g \t" << g << endl;
    cout << "h \t" << h << endl;
    cout << "i \t" << i << endl;
    cout << "j \t" << j << endl;
    cout << "k \t" << k << endl;
    cout << "l \t" << l << endl;
    cout << "m \t" << m << endl;
    cout << "n \t" << n << endl;
    cout << "o \t" << o << endl;
    cout << "p \t" << p << endl;
    cout << "q \t" << q << endl;
    cout << "r \t" << r << endl;
    cout << "s \t" << s << endl;
    cout << "t \t" << t << endl;
    cout << "u \t" << u << endl;
    cout << "v \t" << v << endl;
    cout << "w \t" << w << endl;
    cout << "x \t" << x << endl;
    cout << "y \t" << y << endl;
    cout << "z \t" << z << endl;
    cout << "1 \t" << one << endl;
    cout << "2 \t" << two << endl;
    cout << "3 \t" << three << endl;
    cout << "4 \t" << four << endl;
    cout << "5 \t" << five << endl;
    cout << "6 \t" << six << endl;
    cout << "7 \t" << seven << endl;
    cout << "8 \t" << eight << endl;
    cout << "9 \t" << nine << endl;
    cout << "0 \t" << zero << endl;
    cout << "space \t" << space << endl;
    cout << "Misc. \t" << misc << endl;
}


int main()
{
    translate work;
    work.textToVector();
    return 0;
}
