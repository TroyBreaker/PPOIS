#include"Application.h"

/**
	* @brief Method that turn on application
	* @param object of class application
	*/
bool AppOn(Application*& app) {
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
bool AppOff(Application*& app) {
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
bool IncrVolume(Application*& app, int val) {
	if (app->GetSet()->GetVolume() + val > 100) {
		return 0;
	}
	app->GetSet()->IncrVolume(val);
	return 1;
}

/**
	* @brief Method that reduce volume
	* @param object of class application
	* @param the value by which we reduce
	*/
bool RedVolume(Application*& app, int val) {
	if (app->GetSet()->GetVolume() - val < 0) {
		return 0;
	}
	app->GetSet()->RedVolume(val);
	return 1;
}
/**
	* @brief Method that turn off volume
	* @param object of class application
	*/
bool VolumeOff(Application*& app)
{
	app->GetSet()->SetMuteVolume(app->GetSet()->GetVolume());
	app->GetSet()->SetVolume(0);
	return 1;
}
/**
	* @brief Method that turn on volume
	* @param object of class application
	*/
bool VolumeOn(Application*& app)
{
	app->GetSet()->SetVolume(app->GetSet()->GetMuteVolume());
	app->GetSet()->SetMuteVolume(0);
	return 1;
}
/**
	* @brief Method that add music to playlist
	* @param object of class application
	* @param name of music you want to add
	* \brief music you want to add is being searched amongst all musics in the vector of Music* in class Application
	*/
void AddMusic(Application*& app, string name) {
	if (!app->CheckMusic(name))
		return;
	app->GetPlaylist()->AddMus(app->GetMusic(name));
	return;
}
/**
	* @brief Method that add podcast to playlist
	* @param object of class application
	* @param name of podcast you want to add
	* \brief podcast you want to add is being searched amongst all podcasts in the vector of Podcast* in class Application
	*/
void AddPodcast(Application*& app, string name) {
	if (!app->CheckPodc(name))
		return;
	app->GetPlaylist()->AddRec(app->GetPodcast(name));
	return;
}
/**
	* @brief Method that add band to playlist
	* @param object of class application
	* @param name of band you want to add
	* \brief band you want to add is being searched amongst all bands in the vector of Band* in class Application
	*/
void AddBand(Application*& app, string name) {
	if (!app->GetBand(name))
		return;
	app->GetPlaylist()->AddBand(app->GetBand(name));
	return;
}
/**
	* @brief Method that delete podcast from playlist
	* @param object of class application
	* @param name of podcast you want to delete
	*/
void DelPodcast(Application*& app,string name ) {
	app->GetPlaylist()->DelPodc(name);
}
/**
	* @brief Method that delete music from playlist
	* @param object of class application
	* @param name of music you want to delete
	*/
void DelMusic(Application*& app, string name) {
	app->GetPlaylist()->DelMus(name);
}
/**
	* @brief Method that turn on music to listen
	* @param object of class application
	* @param name of music you want to listen
	*/
void TurnOnMusic(Application*& app, string name)
{
	if (!app->GetMusic(name))
		return;
	app->SetCurrent(app->GetMusic(name));
}
/**
	* @brief Method that turn on podcast to listen
	* @param object of class application
	* @param name of podcast you want to listen
	*/
void TurnOnPodcast(Application*& app, string name)
{
	if (!app->GetPodcast(name))
		return;
	app->SetCurrent(app->GetPodcast(name));
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
	if (!app->GetPlaylist()->GetMusic(name))
		return;
	app->SetCurrent(app->GetPlaylist()->GetMusic(name));
}
/**
	* @brief Method that turn on podcast to listen from playlist
	* @param object of class application
	* @param name of podcast you want to listen from playlist
	*/
void TurnOnPodcastOnPlaylist(Application*& app, string name)
{
	if (!app->GetPlaylist()->GetPodcast(name))
		return;
	app->SetCurrent(app->GetPlaylist()->GetPodcast(name));
}
/**
	* @brief Method that turn on next podcast to listen from playlist
	* @param object of class application
	*/
void TurnOnNextPodcast(Application*& app)
{
	string name = app->GetCurrent()->GetName();
	app->SetCurrent(app->GetPlaylist()->GetNextPodcast(name));
}
/**
	* @brief Method that turn on next music to listen from playlist
	* @param object of class application
	*/
void TurnOnNextMusic(Application*& app)
{
	string name = app->GetCurrent()->GetName();
	app->SetCurrent(app->GetPlaylist()->GetNextMusic(name));
}
/**
	* @brief Method that turn on first music from album from band from playlist
	* @param object of class application
	*/
void TurnOnAlbumOfBandOnPlaylist(Application*& app, string nameOfBand,string nameOfAlbum)
{
	if (!app->GetPlaylist()->GetBand(nameOfBand))
		return;
	if (!app->GetPlaylist()->GetBand(nameOfBand)->GetAlbum(nameOfAlbum))
		return;
	app->SetCurrent(app->GetPlaylist()->GetBand(nameOfBand)->GetAlbum(nameOfAlbum)->GetFirstSong());
}