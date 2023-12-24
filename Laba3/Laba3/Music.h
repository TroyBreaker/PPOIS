#pragma once
#include "Record.h"
#include "Band.h"
/**
* @brief Class of Music for Application and Playlist (derived class)
*/
class Music : public Record
{
	//! genre of music
	string const genre;
public:
	Music(string genre, double length, string name) : genre(genre), Record(length, name) {};
	
	void GetInfo(string& line) const override
	{
		line += (this->GetName() + " ");
		line += this->genre;
	}
};