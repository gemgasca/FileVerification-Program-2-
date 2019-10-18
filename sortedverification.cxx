#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"
#include <map>
#include <vector>
#include <string>

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
    std::cout << jsonObject.dump(2) << std::endl;

    std::map<std::string, std::string> metadata;                    // gets json data
    metadata["array_size"] = jsonObject["metadata"]["arraySize"];
    metadata["num_samples"] = jsonObject["metadata"]["numSamples"];
    metadata["file"] = json_name;
    metadata["samplesWithInversions"] = " ";


    for (int i = 1; i <= std::stoi(metadata["array_size"]); i++) {      // iterates over every sample in the file
        std::string num = std::to_string(i);
        std::string sample = "Sample";
        sample.append(num);
        std::vector<int> vector = jsonObject[sample][i];
    }

//    std::map<std::string, std::map< std::string, std::string>> json_output;       // returned json to be printed to terminal
//    json_output["metadata"] = metadata;
//
//    json_output

    return 0;
}
