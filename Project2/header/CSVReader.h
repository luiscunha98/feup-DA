/**
 * @file CSVReader.h
 * @brief Declaration of the CSVReader class.
 */

#ifndef DA2_CSVREADER_H
#define DA2_CSVREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include "GraphAM.h"

/**
 * @class CSVReader
 * @brief Contains static methods for reading data from CSV files.
 */
class CSVReader {
public:
    /**
     * @brief Default constructor for CSVReader.
     */
    CSVReader();

    /**
     * @brief Reads the data from a CSV file and constructs a Traveling Salesman Problem (TSP) graph using an adjacency matrix representation.
     * @param file The name of the CSV file.
     * @param graph Pointer to the GraphAM object where the data will be stored.
     */
    static void read_TG(const std::string& file, GraphAM& graph);
    static void read_RWG(std::string &file, GraphAM& graph);

};

#endif //DA2_CSVREADER_H
