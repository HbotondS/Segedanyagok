#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    vector<string> v;	// dinamikus tomb
    cout<<"Irjon be karakterlancokat vegjelig (Unix: Ctrl D, Windows: Ctrl Z): "<<endl;
    copy(istream_iterator<string>(cin),istream_iterator<string>(), back_inserter(v));	// a standard inputrol a szoveget
																						// bemasolja a v valtozoba
																						// mindig a tomb vegere szurjuk be
																						// az uj elemet
    sort(v.begin(), v.end());	// rendezi a tombot (alapertelmezett -> abc szerint)
    cout<<"A kimenet:"<<endl;
    copy( v.begin(), v.end(), ostream_iterator<string>(cout,"\n"));	// v tartalmat kimasolja a standard kimenetre
    return 0;
}