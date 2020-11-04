CXX=g++

all: build

build:
	$(CXX) -std=c++11 -o main src/main.cpp src/Channel.cpp src/File.cpp src/Image.cpp src/ImageData.cpp src/ImageTools.cpp src/ImageVector.cpp

run:
	@./main