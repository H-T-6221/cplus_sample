#pragma once

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>

class ReadFile {
    private:
        std::string data;
    public:
        void read(std::string file_path) {
            std::ifstream ifs(file_path, std::ios::binary); // バイナリモードでファイルを開く
            std::stringstream file_data;
            if (!ifs) {
                std::cerr << "Failed to open file." << std::endl;
                return;
            }

            file_data << ifs.rdbuf(); // ファイルデータを一度に読み込む

            if (file_data.str().empty()) {
                std::cerr << "File size error." << std::endl;
                return;
            }
            data = file_data.str();
            return;
        }
        std::string get() {
            return data;
        }
};
