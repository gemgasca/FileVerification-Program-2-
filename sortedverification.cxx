#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"
#include <map>
#include <vector>

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

//    for (auto itr = jsonObject.begin(); itr != jsonObject.end(); ++itr) {
//        std::cout << "key: " << itr.key() << " value: " << itr.value() << std::endl;
//        std::string sample_name = itr.key();
////        std::vector<int> data;
//        auto data = itr.value();
//
////        if (typeid(itr.value()) == typeid(data)){
////
////        }
//    }

//    std::vector<int> vector;
//    for (auto i = jsonObject.begin(); i != jsonObject.end(); i++) {
//        jsonObject["Sample1"][i] >> vector;
//    }



//    std::map<std::string, std::string> metadata;
//    metadata["array_size"] = jsonObject["metadata"]["arraySize"];
//    metadata["num_samples"] = jsonObject["metadata"]["numSamples"];
//    metadata["file"] = json_name;
//    metadata["samplesWithInversions"] = " ";
//
//
//
//    std::map<std::string, std::map< std::string, std::string>> json_output;
//    json_output["metadata"] = metadata;
//
//    json_output

    return 0;
}