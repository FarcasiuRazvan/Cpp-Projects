#include "DogValidator.h"

using namespace std;

DogException::DogException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> DogException::getErrors() const
{
	return this->errors;
}

void DogValidator::validate(const dog & s)
{
	vector<string> errors;
	if (s.getBreed().size() < 3)
		errors.push_back("The breed cannot be less than 2 characters!\n");
	if (!isupper(s.getName()[0]))
		errors.push_back(string("The name must start with a capital letter!\n"));

	if (errors.size() > 0)
		throw DogException(errors);
}
