#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Music.h"
#include "Podcast.h"
#include "Band.h"
using namespace std;
/**
* @brief Class of Playlist for Application
*/
class Playlist {
	//! vector of musics in playlist
	vector<Music*> musics;
	//! vector of podcasts in playlist
	vector<Podcast*> podcasts;
	//! vector of bands in playlist
	vector<Band*> listOfBands;
public:
	Playlist() {}

	void AddMusic(Music* music)
	{
		if(!CheckMusic(music->GetName()))
		musics.push_back(music);
	}
	void AddPodcast(Podcast* podcast)
	{
		if (!CheckPodcast(podcast->GetName()))
		podcasts.push_back(podcast);
	}

	void AddBand(Band* band)
	{
		if (!CheckBand(band->GetName()))
			listOfBands.push_back(band);
	}

	void DeleteMusic(string name)
	{
		if (CheckMusic(name))
		{
			for (int i = 0; i < musics.size(); i++)
				if (musics[i]->GetName() == name)
					musics.erase(musics.begin() + i);
		}
	}
	void DeletePodcast(string name)
	{
		if (CheckPodcast(name))
		{
			for (int i = 0; i < podcasts.size(); i++)
				if (podcasts[i]->GetName() == name)
					podcasts.erase(podcasts.begin() + i);
		}
	}

	bool CheckMusic(string name) const
	{
		for (Music* mus : musics)
			if (mus->GetName() == name)
				return 1;
		return 0;
	}
	bool CheckPodcast(string name) const
	{
		for (Podcast* mus : podcasts)
			if (mus->GetName() == name)
				return 1;
		return 0;
	}
	bool CheckBand(string name) const
	{
		for (Band* mus : listOfBands)
			if (mus->GetName() == name)
				return 1;
		return 0;
	}

	Music* GetMusic(string name) const
	{
		for (int i = 0; i < musics.size(); i++)
			if (musics[i]->GetName() == name)
				return musics[i];
		return NULL;
	}
	Music* GetNextMusic(string name) const
	{
		for (int i = 0; i < musics.size(); i++) {
			if (musics[i]->GetName() == name) {
				if (i != musics.size() - 1) {
					return musics[i + 1];
				}
				else throw new exception("Last music");
			}
		}
		
	}
	
	Podcast* GetPodcast(string name) const
	{
		for (int i = 0; i < podcasts.size(); i++)
			if (podcasts[i]->GetName() == name)
				return podcasts[i];
		return NULL;
	}
	Podcast* GetNextPodcast(string name) const
	{
		for (int i = 0; i < podcasts.size(); i++)
			if (podcasts[i]->GetName() == name)
				if(i!=podcasts.size()-1)
				return podcasts[i+1];
				else  throw new exception("Last podcast");
		
	}
	Band* GetBand(string name) const
	{
		for (int i = 0; i < listOfBands.size(); i++)
			if (listOfBands[i]->GetName() == name)
				return listOfBands[i];
		return NULL;
	}
};