#pragma once
#include "Album.h"
/**
* @brief Class of Band for Application and Playlist
*/
class Band {
	//! albums of band
	vector<Album*> albums;
	//! name of band
	string const name;
public:
	Band(string name) : name(name) {};
	string GetName()  const
	{
		return name;
	}
	void SetAlbums(Album*album) 
	{
		albums.push_back(album);
	}
	Album* GetAlbum(string name)const
	{
		for (int i = 0; i < albums.size(); i++)
			if (albums[i]->GetName() == name)
				return albums[i];
		return NULL;
	}
};