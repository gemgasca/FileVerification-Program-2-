#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"
#include <map>
#include <vector>
#include <string>
#include <typeinfo>

bool find_inversions(const std::vector<int>& values, nlohmann::json& jsonOutput, std::string sample_name){
    int inversions = 0;
    std::map<std::string, std::vector<int>> consecutive_inversions;         // checks for inversions
    for (int i = 0; i < values.size() - 1; i++){
        int next_val = i+1;
        if (values[i] > values[next_val]){
            inversions++;
            std::vector<int> inverted_values;
            inverted_values.push_back(values[i]);
            inverted_values.push_back(values[next_val]);
            consecutive_inversions[std::to_string(inversions)] = inverted_values;
        }
    }

    if (consecutive_inversions.size() > 0) {
        std::vector<int> this_sample;
        for (int elem: values) {
            this_sample.push_back(elem);
        }
        jsonOutput[sample_name]["ConsecutiveInversions"] = consecutive_inversions;
        jsonOutput[sample_name]["sample"] = this_sample;
        return true;
    }

    return false;
}

int main(int argc, char** argv) {
    nlohmann::json jsonObject;

    std::string json_name = argv[1];    // open file
    std::ifstream json_file;
    json_file.open(json_name);

    if (json_file.is_open()){           // prints json object and its contents
        json_file >> jsonObject;
    }
//    std::cout << jsonObject.dump(2) << std::endl;

    nlohmann::json jsonOutput;  // creates out put object

    int samplesWithInversions = 0;
    for (int i = 1; i <= jsonObject["metadata"]["numSamples"]; i++) {      // iterates over every sample in the file
        std::string num = std::to_string(i);
        std::string sample_name = "Sample";
        sample_name.append(num);

        std::vector<int> vector;
        for (int i = 0; i < jsonObject["metadata"]["arraySize"]; i++) {
            auto x = jsonObject[sample_name][i];
            vector.push_back(x);
        }

        if (find_inversions(vector, jsonOutput, sample_name)){
            samplesWithInversions++;
        }
    }

    jsonOutput["metadata"]["array_size"] = jsonObject["metadata"]["arraySize"];
    jsonOutput["metadata"]["num_samples"] = jsonObject["metadata"]["numSamples"];
    jsonOutput["metadata"]["file"] = json_name;
    jsonOutput["metadata"]["samplesWithInversions"] = samplesWithInversions;
    std::cout << jsonOutput.dump(2) << std::endl;
    
    return 0;
}
