#ifndef RENDERING_UTILS_H
#define RENDERING_UTILS_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "ConsoleUtils.h"
#include "Position.h"

class Renderer {
public:
private:
	const size_t size;
	std::vector<std::vector<char> > renderBuffer;
public:
	explicit Renderer(size_t size) : size(size) {
		for (size_t r = 0; r < size; r++) {
			std::vector<char> bufferRow;
			for (size_t c = 0; c < size; c++) {
				bufferRow.push_back(' ');
			}
			renderBuffer.push_back(bufferRow);
		}
	}

	void render(Position p, std::string image) {
		for (size_t i = 0; i < image.size() && p.getCol() + i < size; i++) {
			renderBuffer[p.getRow()][p.getCol() + i] = image[i];
		}
	}

	void flushToScreen() {
		std::ostringstream output;
		for (size_t r = 0; r < size; r++) {
			for (size_t c = 0; c < size; c++) {
				output << this->renderBuffer[r][c];
				this->renderBuffer[r][c] = ' ';
			}
			output << std::endl;
		}

		clearScreen();
		std::cout << output.str() << std::endl;
	}
};

#endif // !RENDERING_UTILS_H
