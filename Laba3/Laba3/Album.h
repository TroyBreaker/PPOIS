#pragma once
class Music;
/**
* @brief Class of Album for Band
*/
class Album {
	vector<Music*> songs;
	string name;
public:
	Album(string name, vector<Music*> songs) {
		this->name = name;
		for (int i = 0; i < songs.size(); i++)
			this->songs.push_back(songs[i]);
	}
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