#pragma once
#include "Playlist.h"
#include"Settings.h"
using namespace std;
/**
* @brief Class of Application
*/
class Application {
	//! name of application
	string name;
	
	//! state of application, 0-turn off, 1-turn on
	bool state = 0;
	//! current record, record that you listen now
	Record* current = NULL;
	//! your playlist
	Playlist* playlist;
	//! setting of application
	Settings* settings;
	//! vector of all musics you can listen (all music you can search)
	vector<Music*> listOfMusic;
	//! vector of all podcasts you can listen (all podcasts you can search)
	vector<Podcast*> listOfPodcast;
	//! vector of all bands you can listen (all bands you can search)
	vector<Band*> listOfBands;
public:
	Application(string name, Playlist* playlist, Settings* settings)
	{
		this->name = name;
		this->playlist = playlist;
		this->settings = settings;
	}
	
	void SetCurrent(Record* current)
	{
		this->current = current;
	}
	Record* GetCurrent() const
	{
		return current;
	}
	Settings* GetSettings() const
	{
		return settings;
	}

	bool GetState() const
	{
		return state;
	}

	void SetState(bool state) 
	{
		this->state = state;
	}

	Playlist* GetPlaylist() const
	{
		return playlist;
	}

	void SetListOfBands(vector<Band*> ListOfBands)
	{
		for (Band* band : ListOfBands)
			this->listOfBands.push_back(band);
	}
	void AddBand(Band* music)
	{
		this->listOfBands.push_back(music);
	}

	void SetListOfMusic(vector<Music*> ListOfMusic)
	{
		for (Music* music : ListOfMusic)
			this->listOfMusic.push_back(music);
	}
	void AddMusic(Music* music)
	{
		this->listOfMusic.push_back(music);
	}
	void SetListOfPodcast(vector<Podcast*> ListOfPodcast)
	{
		for (Podcast* podcast : ListOfPodcast)
			this->listOfPodcast.push_back(podcast);
	}
	void AddPodcast(Podcast* podcast)
	{
		this->listOfPodcast.push_back(podcast);
	}

	Music* GetMusic(string name) const
	{
		for (int i = 0; i < listOfMusic.size(); i++)
			if (listOfMusic[i]->GetName() == name)
				return listOfMusic[i];
		return NULL;
	}
	Podcast* GetPodcast(string name) const
	{
		for (int i = 0; i < listOfPodcast.size(); i++)
			if (listOfPodcast[i]->GetName() == name)
				return listOfPodcast[i];
		return NULL;
	}

	Band* GetBand(string name) const
	{
		for (int i = 0; i < listOfBands.size(); i++)
			if (listOfBands[i]->GetName() == name)
				return listOfBands[i];
		return NULL;
	}
};