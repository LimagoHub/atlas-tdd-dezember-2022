#include <iostream>
#include "ToUpperTranslator.h"
#include "TranslatorClient.h"
int main() {
	ToUpperTranslator translator;
	TranslatorClient client{translator};

	client.go();
}