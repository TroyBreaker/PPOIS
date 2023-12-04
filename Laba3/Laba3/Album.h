#pragma once
class Music;
/**
* @brief Class of Album for Band
*/
class Album {
	//! songs in album
	vector<Music*> songs;
	//! name of album
	string name;
public:
	Album(string name)
	{
		this->name = name;
	}
	void AddMusic(Music* mus)
	{
		this->songs.push_back(mus);
	}
	string GetName()
	{
		return name;
	}
	Music* GetFirstSong()
	{
		return songs[0];
	}
};