#pragma once
#include <string>

class painting
{
protected:
	std::string title;
	std::string artist;
	int year;
public:
	painting() {};
	painting(const std::string title, const std::string artist, const int year) { this->title = title; this->artist = artist; this->year = year; }

	std::string getTitle() { return this->title; }
	std::string getArtist() { return this->artist; }
	int getYear() { return this->year; }
};