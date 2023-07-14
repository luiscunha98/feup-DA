#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <locale>
#include <codecvt>
#include "newGraph.h"

using namespace std;

class Utils {
public:
    static Graph readGraph();
    static string replaceSpecialChars(string s);
};

#endif
