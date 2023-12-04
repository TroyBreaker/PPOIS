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
	//! vector of all musics you can listen
	vector<Music*> ListOfMusic;
	//! vector of all podcasts you can listen
	vector<Podcast*> ListOfPodcast;
	//! vector of all bands you can listen
	vector<Band*> ListOfBands;
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
	Record* GetCurrent()
	{
		return current;
	}
	Settings* GetSet() {
		return settings;
	}

	bool GetState()
	{
		return state;
	}

	void SetState(bool state) {
		this->state = state;
	}

	Playlist* GetPlaylist()
	{
		return playlist;
	}

	void SetListOfBands(vector<Band*> ListOfBands)
	{
		for (Band* mus : ListOfBands)
			this->ListOfBands.push_back(mus);
	}
	void AddBand(Band* mus)
	{
		this->ListOfBands.push_back(mus);
	}

	void SetListOfMusic(vector<Music*> ListOfMusic)
	{
		for (Music* mus : ListOfMusic)
			this->ListOfMusic.push_back(mus);
	}
	void AddMusic(Music* mus)
	{
		this->ListOfMusic.push_back(mus);
	}
	void SetListOfPodcast(vector<Podcast*> ListOfPodcast)
	{
		for (Podcast* mus : ListOfPodcast)
			this->ListOfPodcast.push_back(mus);
	}
	void AddPodcast(Podcast* mus)
	{
		this->ListOfPodcast.push_back(mus);
	}
	bool CheckMusic(string name)
	{
		for (Music* mus : ListOfMusic)
			if (mus->GetName() == name)
				return 1;
		return 0;
	}
	bool CheckPodc(string name)
	{
		for (Podcast* mus : ListOfPodcast)
			if (mus->GetName() == name)
				return 1;
		return 0;
	}

	Music* GetMusic(string name)
	{
		for (int i = 0; i < ListOfMusic.size(); i++)
			if (ListOfMusic[i]->GetName() == name)
				return ListOfMusic[i];
		return NULL;
	}
	Podcast* GetPodcast(string name)
	{
		for (int i = 0; i < ListOfPodcast.size(); i++)
			if (ListOfPodcast[i]->GetName() == name)
				return ListOfPodcast[i];
		return NULL;
	}

	Band* GetBand(string name)
	{
		for (int i = 0; i < ListOfBands.size(); i++)
			if (ListOfBands[i]->GetName() == name)
				return ListOfBands[i];
		return NULL;
	}
};