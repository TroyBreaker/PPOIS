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
	vector<Music*> musics;
	vector<Podcast*> podcasts;
	vector<Band*> ListOfBands;
public:
	Playlist(vector<Music*> vector_music,vector<Podcast*> vector_podcast)
	{
		for (int i = 0; i < vector_music.size(); i++)
		{
			this->musics[i] = vector_music[i];
		}
		for (int i = 0; i < vector_podcast.size(); i++)
		{
			this->podcasts[i] = vector_podcast[i];
		}
	}
	Playlist() {}

	void AddMus(Music* rec)
	{
		if(!CheckMus(rec->GetName()))
		musics.push_back(rec);
	}
	void AddRec(Podcast* rec)
	{
		if (!CheckPodc(rec->GetName()))
		podcasts.push_back(rec);
	}

	void AddBand(Band* rec)
	{
		if (!CheckBand(rec->GetName()))
			ListOfBands.push_back(rec);
	}

	void DelMus(string name)
	{
		if (CheckMus(name))
		{
			for (int i = 0; i < musics.size(); i++)
				if (musics[i]->GetName() == name)
					musics.erase(musics.begin() + i);
		}
	}
	void DelPodc(string name)
	{
		if (CheckPodc(name))
		{
			for (int i = 0; i < podcasts.size(); i++)
				if (podcasts[i]->GetName() == name)
					podcasts.erase(podcasts.begin() + i);
		}
	}

	bool CheckMus(string name)
	{
		for (Music* mus : musics)
			if (mus->GetName() == name)
				return 1;
		return 0;
	}
	bool CheckPodc(string name)
	{
		for (Podcast* mus : podcasts)
			if (mus->GetName() == name)
				return 1;
		return 0;
	}
	bool CheckBand(string name)
	{
		for (Band* mus : ListOfBands)
			if (mus->GetName() == name)
				return 1;
		return 0;
	}

	Music* GetMusic(string name)
	{
		for (int i = 0; i < musics.size(); i++)
			if (musics[i]->GetName() == name)
				return musics[i];
		return NULL;
	}
	Music* GetNextMusic(string name)
	{
		for (int i = 0; i < musics.size(); i++)
			if (musics[i]->GetName() == name)
				if(i!= musics.size()-1)
				return musics[i+1];
		return NULL;
	}
	
	Podcast* GetPodcast(string name)
	{
		for (int i = 0; i < podcasts.size(); i++)
			if (podcasts[i]->GetName() == name)
				return podcasts[i];
		return NULL;
	}
	Podcast* GetNextPodcast(string name)
	{
		for (int i = 0; i < podcasts.size(); i++)
			if (podcasts[i]->GetName() == name)
				if(i!=podcasts.size()-1)
				return podcasts[i+1];
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