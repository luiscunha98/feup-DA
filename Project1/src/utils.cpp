#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "utils.h"

using namespace std;
Graph Utils::readGraph() {
    setlocale(LC_ALL, "en_US.UTF-8"); // move setlocale() function calls outside while loops

    ifstream file("../data/stations.csv");
    if (!file.is_open()) cout << "file not found" << endl;
    string text, name, district, municipality, township, line;
    Graph g;
    getline(file, text, '\n');
    while (getline(file, text)) {

        text = replaceSpecialChars(text);

        vector<string> v;
        stringstream ss(text);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }

        name = v[0];
        district = v[1];
        municipality = v[2];
        township = v[3];
        line = v[4];

        g.addVertex(name, district, municipality, township, line);
    }

    ifstream file2("../data/network.csv");
    if (!file2.is_open()) cout << "file not found" << endl;
    string sourc, dest, w, service;
    getline(file2, text, '\n');

    while (getline(file2, text)) {

        text = replaceSpecialChars(text);

        vector<string> v2;
        stringstream ss(text);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v2.push_back(substr);
        }

        sourc = v2[0];
        dest = v2[1];
        w = v2[2];
        service = v2[3];

        g.addEdge(sourc, dest, stoi(w), service);
    }
    return g;
}



string Utils::replaceSpecialChars(string s) {
    // Convert the input string to UTF-8 encoding
    wstring_convert<codecvt_utf8<char32_t>, char32_t> converter;
    u32string utf32 = converter.from_bytes(s);

    // Replace the special characters
    for (auto& c : utf32) {
        switch (c) {
            case U'á': c = U'a'; break;
            case U'Á': c = U'A'; break;
            case U'à': c = U'a'; break;
            case U'À': c = U'A'; break;
            case U'ã': c = U'a'; break;
            case U'Â': c = U'A'; break;
            case U'â': c = U'a'; break;
            case U'Ã': c = U'A'; break;
            case U'é': c = U'e'; break;
            case U'É': c = U'E'; break;
            case U'è': c = U'e'; break;
            case U'È': c = U'E'; break;
            case U'Ê': c = U'E'; break;
            case U'ê': c = U'e'; break;
            case U'Ì': c = U'I'; break;
            case U'í': c = U'i'; break;
            case U'Í': c = U'I'; break;
            case U'ì': c = U'i'; break;
            case U'î': c = U'i'; break;
            case U'Î': c = U'I'; break;
            case U'ó': c = U'o'; break;
            case U'ò': c = U'o'; break;
            case U'Ó': c = U'O'; break;
            case U'Ò': c = U'O'; break;
            case U'Õ': c = U'O'; break;
            case U'õ': c = U'o'; break;
            case U'Ô': c = U'O'; break;
            case U'ô': c = U'o'; break;
            case U'ú': c = U'u'; break;
            case U'ù': c = U'u'; break;
            case U'Ú': c = U'U'; break;
            case U'Ù': c = U'U'; break;
            case U'ç': c = U'c'; break;
            case U'º': c = U'.'; break;
            case U'–': c = U'-'; break;
            case U'"': c = U' '; break;


                // add more cases as needed
        }
    }

    // Convert the string back to UTF-8 encoding
    return converter.to_bytes(utf32);
}