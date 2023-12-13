#include"Application.h"

/**
	* @brief Method that turn on application
	* @param object of class application
	*/
bool AppOn(Application*& app) 
{
	if (app->GetState() == 0) {
		app->SetState(1);
		return 1;
	}
	else
		return 0;
}
/**
	* @brief Method that turn off application
	* @param object of class application
	*/
bool AppOff(Application*& app) 
{
	if (app->GetState() == 1) {
		app->SetState(0);
		return 1;
	}
	else
		return 0;
}
/**
	* @brief Method that increase volume
	* @param object of class application
	* @param the value by which we increase
	*/
bool IncreaseVolume(Application*& app, int val) 
{

	if (app->GetSettings()->GetVolume() + val > app->GetSettings()->GetMaxVolume()) {
		return 0;
	}
	app->GetSettings()->IncrVolume(val);
	return 1;
}

/**
	* @brief Method that reduce volume
	* @param object of class application
	* @param the value by which we reduce
	*/
bool ReduceVolume(Application*& app, int val) 
{
	if (app->GetSettings()->GetVolume() - val < app->GetSettings()->GetMinVolume()) {
		return 0;
	}
	app->GetSettings()->RedVolume(val);
	return 1;
}
/**
	* @brief Method that turn off volume
	* @param object of class application
	*/
bool VolumeOff(Application*& app)
{
	app->GetSettings()->SetMuteVolume(app->GetSettings()->GetVolume());
	app->GetSettings()->SetVolume(0);
	return 1;
}
/**
	* @brief Method that turn on volume
	* @param object of class application
	*/
bool VolumeOn(Application*& app)
{
	app->GetSettings()->SetVolume(app->GetSettings()->GetMuteVolume());
	app->GetSettings()->SetMuteVolume(0);
	return 1;
}
/**
	* @brief Method that add music to playlist
	* @param object of class application
	* @param name of music you want to add
	* \brief music you want to add is being searched amongst all musics in the vector of Music* in class Application
	*/
void AddMusic(Application*& app, string name) 
{
	Music* added = app->GetMusic(name);
	if (!added)
		return;
	app->GetPlaylist()->AddMusic(added);
	return;
}
/**
	* @brief Method that add podcast to playlist
	* @param object of class application
	* @param name of podcast you want to add
	* \brief podcast you want to add is being searched amongst all podcasts in the vector of Podcast* in class Application
	*/
void AddPodcast(Application*& app, string name) 
{
	Podcast* added = app->GetPodcast(name);
	if (!added)
		return;
	app->GetPlaylist()->AddPodcast(added);
	return;
}
/**
	* @brief Method that add band to playlist
	* @param object of class application
	* @param name of band you want to add
	* \brief band you want to add is being searched amongst all bands in the vector of Band* in class Application
	*/
void AddBand(Application*& app, string name) 
{
	Band* added = app->GetBand(name);
	if (!added)
		return;
	app->GetPlaylist()->AddBand(added);
	return;
}
/**
	* @brief Method that delete podcast from playlist
	* @param object of class application
	* @param name of podcast you want to delete
	*/
void DeletePodcastFomPlaylist(Application*& app,string name ) 
{
	app->GetPlaylist()->DeletePodcast(name);
}
/**
	* @brief Method that delete music from playlist
	* @param object of class application
	* @param name of music you want to delete
	*/
void DeleteMusicFromPlaylist(Application*& app, string name) 
{
	app->GetPlaylist()->DeleteMusic(name);
}
/**
	* @brief Method that turn on music to listen
	* @param object of class application
	* @param name of music you want to listen
	*/
void TurnOnMusic(Application*& app, string name)
{
	Music* turned = app->GetMusic(name);
	if (!turned)
		return;
	app->SetCurrent(turned);
}
/**
	* @brief Method that turn on podcast to listen
	* @param object of class application
	* @param name of podcast you want to listen
	*/
void TurnOnPodcast(Application*& app, string name)
{
	Podcast* turned = app->GetPodcast(name);
	if (!turned)
		return;
	app->SetCurrent(turned);
}
/**
	* @brief Method that turn off listening record
	* @param object of class application
	*/
void TurnOffRecord(Application*& app)
{
	app->SetCurrent(NULL);
}
/**
	* @brief Method that turn on music to listen from playlist
	* @param object of class application
	* @param name of music you want to listen from playlist
	*/
void TurnOnMusicOnPlaylist(Application*& app, string name)
{
	Music* turned = app->GetPlaylist()->GetMusic(name);
	if (!turned)
		return;
	app->SetCurrent(turned);
}
/**
	* @brief Method that turn on podcast to listen from playlist
	* @param object of class application
	* @param name of podcast you want to listen from playlist
	*/
void TurnOnPodcastOnPlaylist(Application*& app, string name)
{
	Podcast* turned = app->GetPlaylist()->GetPodcast(name);
	if (!turned)
		return;
	app->SetCurrent(turned);
}
/**
	* @brief Method that turn on next podcast to listen from playlist
	* @param object of class application
	*/
void TurnOnNextPodcast(Application*& app)
{
	string name = app->GetCurrent()->GetName();
	try {
		Podcast* nextPodcast = app->GetPlaylist()->GetNextPodcast(name);
		app->SetCurrent(nextPodcast);
	}
	catch (const exception* ex)
	{
		app->SetCurrent(NULL);
		cout << ex->what() << endl;
	}
}
/**
	* @brief Method that turn on next music to listen from playlist
	* @param object of class application
	*/
void TurnOnNextMusic(Application*& app)
{
	string name = app->GetCurrent()->GetName();
	try {
		Music* nextMusic = app->GetPlaylist()->GetNextMusic(name);
		app->SetCurrent(nextMusic);
	}
	catch (const exception* ex)
	{
		app->SetCurrent(NULL);
		cout << ex->what() << endl;
	}
}
/**
	* @brief Method that turn on first music from album from band from playlist
	* @param object of class application
	*/
void TurnOnAlbumOfBandOnPlaylist(Application*& app, string nameOfBand,string nameOfAlbum)
{
	Band* wantedBand = app->GetPlaylist()->GetBand(nameOfBand);
	if (!wantedBand)
		return;
	Album* turnedAlbum = wantedBand->GetAlbum(nameOfAlbum);
	if (!turnedAlbum)
		return;
	app->SetCurrent(turnedAlbum->GetFirstSong());
}