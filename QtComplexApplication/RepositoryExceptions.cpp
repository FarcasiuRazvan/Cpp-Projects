#include "RepositoryExceptions.h"

FileException::FileException(const std::string & msg) : message(msg)
{
}

const char * FileException::what()
{
	return message.c_str();
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string & msg) : message{ msg }
{
}

const char * RepositoryException::what()
{
	return this->message.c_str();
}

const char * DuplicateDogException::what()
{
	return "There is another dog with the same name and breed!";
}

const char * ExistDogException::what()
{
	return "There is no dog with the name and breed you entered!";
}