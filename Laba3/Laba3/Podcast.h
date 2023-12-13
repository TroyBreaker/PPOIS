#pragma once
#include "Record.h"
/**
* @brief Class of Podcast for Application and Playlist (derived class)
*/
class Podcast :public Record
{
	//! name of talker
	string talker;
	//! theme of podcast
	string theme;
public:
	Podcast(string talker, string theme, double length, string name) :Record(length, name)
	{
		this->talker = talker;
		this->theme = theme;
	}
	void GetInfo(string& line) const override
	{
		line += (this->GetName() + " ");
		line += (this->talker + " ");
		line += this->theme;
	}
};