#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

std::string readFileToHex(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return "";
    }

    std::ostringstream oss;
    unsigned char byte;
    while (file >> std::noskipws >> byte) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }

    return oss.str();
}

int main() {
    std::string filePath = "xor.txt";
    std::string hexContent = readFileToHex(filePath);

    if (!hexContent.empty()) {
        std::cout << "Hexadecimal content of " << filePath << ":\n";
        std::cout << hexContent << std::endl;
    }

    return 0;
}

