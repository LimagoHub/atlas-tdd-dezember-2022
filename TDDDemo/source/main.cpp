#include <iostream>
#include "ToUpperTranslator.h"
#include "TranslatorClient.h"
int main() {

	TranslatorClient client{std::make_unique<ToUpperTranslator>()};

	client.go();
}