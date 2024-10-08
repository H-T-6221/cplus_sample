#include "log.h"

void Log::print(std::string massage) {
    std::ofstream outputfile;
    outputfile.open("log.txt", std::ios::app);
    outputfile << massage << std::endl;
    outputfile.close();
}

/*
int main() {
    Log Log;
    Log.print("test");
    return 0;
}
*/
