#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"
#include <map>
#include <vector>
#include <string>

bool find_inversions(const std::vector<int>& values, nlohmann::json& jsonOutput, std::string sample_name){
    std::map<std::string, std::vector<int>> consecutive_inversions;         // checks for inversions
    for (int i = 0; i < values.size() - 1; i++){
        int next_val = i+1;
        if (values[i] > values[next_val]){                  // checks for if the value is bigger than next

            std::vector<int> inverted_values;
            inverted_values.push_back(values[i]);           // adds inverted values to vector
            inverted_values.push_back(values[next_val]);

            consecutive_inversions[std::to_string(i)] = inverted_values;
        }
    }

    if (consecutive_inversions.size() > 0) {                // if there are inversions
        std::vector<int> this_sample;                       // formats jsonOutput
        jsonOutput[sample_name]["ConsecutiveInversions"] = consecutive_inversions;
        jsonOutput[sample_name]["sample"] = values;
        return true;
    }

    return false;
}

int main(int argc, char** argv) {
    nlohmann::json jsonObject;

    std::string json_name = argv[1];    // opens argument file
    std::ifstream json_file;
    json_file.open(json_name);

    json_file >> jsonObject;            // reads json data into object

                                        //    std::cout << jsonObject.dump(2) << std::endl;
    nlohmann::json jsonOutput;          // creates out put object

    int samplesWithInversions = 0;
    for (int i = 1; i <= jsonObject["metadata"]["numSamples"]; i++) {      // iterates over every sample in the file
        std::string num = std::to_string(i);
        std::string sample_name = "Sample";
        if (i < 10) {
            sample_name.append("0");
        }
        sample_name.append(num);

        std::vector<int> vector;                                            // iterates over every number in sample
        for (int i = 0; i < jsonObject["metadata"]["arraySize"]; i++) {
            int x = jsonObject[sample_name][i];
            vector.push_back(x);
        }

        if (find_inversions(vector, jsonOutput, sample_name)){              // finds the inversions
            samplesWithInversions++;
        }
    }


    jsonOutput["metadata"]["arraySize"] = jsonObject["metadata"]["arraySize"]; // formats jsonOutput
    jsonOutput["metadata"]["file"] = json_name;
    jsonOutput["metadata"]["numSamples"] = jsonObject["metadata"]["numSamples"];
    jsonOutput["metadata"]["samplesWithInversions"] = samplesWithInversions;
    std::cout << jsonOutput.dump(2) << std::endl;

    std::ofstream outFile;                                                  // creates file of output for testing purposes
    outFile.open("SV_results.json", std::ios::out);
    outFile << jsonOutput.dump(2);

    json_file.close();
    outFile.close();
    return 0;
}