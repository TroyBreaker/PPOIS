#pragma once
#include "Album.h"
/**
* @brief Class of Band for Application and Playlist
*/
class Band {
	//! albums of band
	vector<Album*> albums;
	//! name of band
	string name;
public:
	Band(string name) {
		this->name = name;
	}
	string GetName() {
		return name;
	}
	void SetAlbums(Album*album)
	{
		albums.push_back(album);
	}
	Album* GetAlbum(string name)
	{
		for (int i = 0; i < albums.size(); i++)
			if (albums[i]->GetName() == name)
				return albums[i];
		return NULL;
	}
};