#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"
#include <map>
#include <vector>
#include <string>
#include <typeinfo>

// the idea:
// check to see if it is sorted
// if it isn't, return json that has stuff that isn't sorted
// "prints the contents of a JSON object to the screen"

int main(int argc, char** argv) {
    nlohmann::json jsonObject;

    std::string json_name = argv[1];    // open file
    std::ifstream json_file;
    json_file.open(json_name);

    if (json_file.is_open()){           // prints json object and its contents
        json_file >> jsonObject;
    }
//    std::cout << jsonObject.dump(2) << std::endl;


//    std::map<std::string, std::string> metadata;                    // gets json data
//    metadata["array_size"] = *jsonObject["metadata"]["arraySize"];
//    metadata["num_samples"] = *jsonObject["metadata"]["numSamples"];
//    metadata["file"] = json_name;
//    metadata["samplesWithInversions"] = " ";

    std::vector<int> vector;
    for (int i = 1; i <= std::stoi("2"); i++) {      // iterates over every sample in the file, metadata["array_size")
        std::string num = std::to_string(i);
        std::string sample = "Sample";
        sample.append(num);
        std::vector<int> vector;
        for (auto itr = jsonObject[sample].begin(); itr != jsonObject[sample].end(); itr++) {
            std::cout << *itr << std::endl;
            vector.push_back(*itr);
        }

    }

    for (auto elem: vector){
        std::cout << "here " << elem << std::endl;
    }

    return 0;
}
