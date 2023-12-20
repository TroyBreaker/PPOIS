#pragma once
class Music;
/**
* @brief Class of Album for Band
*/
class Album {
	//! songs in album
	vector<Music*> songs;
	//! name of album
	const string name;
public:
	Album(string name) : name(name) {}
	void AddMusic(Music* music)
	{
		this->songs.push_back(music);
	}
	string GetName()const
	{
		return name;
	}
	Music* GetFirstSong()const
	{
		return songs[0];
	}
};