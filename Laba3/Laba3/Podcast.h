#pragma once
#include "Record.h"
/**
* @brief Class of Podcast for Application and Playlist (derived class)
*/
class Podcast :public Record
{
	//! name of talker
	string const talker;
	//! theme of podcast
	string const theme;
public:
	Podcast(string talker, string theme, double length, string name) :talker(talker), theme(theme), Record(length, name)
	{};
	void GetInfo(string& line) const override
	{
		line += (this->GetName() + " ");
		line += (this->talker + " ");
		line += this->theme;
	}
};