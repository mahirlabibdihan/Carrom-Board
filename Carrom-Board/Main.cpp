#include "main.h"
#include "Carrom.h"
int main(int argc, char** argv) {
	Carrom::getSingleton()->run(argc, argv);
}