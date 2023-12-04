#include"Application.h"

bool AppOn(Application*& app) {
	if (app->GetState() == 0) {
		app->SetState(1);
		return 1;
	}
	else
		return 0;
}

bool AppOff(Application*& app) {
	if (app->GetState() == 1) {
		app->SetState(0);
		return 1;
	}
	else
		return 0;
}

bool IncrVolume(Application*& app, int val) {
	if (app->GetSet()->GetVolume() + val > 100) {
		return 0;
	}
	app->GetSet()->IncrVolume(val);
	return 1;
}

bool RedVolume(Application*& app, int val) {
	if (app->GetSet()->GetVolume() - val < 0) {
		return 0;
	}
	app->GetSet()->RedVolume(val);
	return 1;
}

bool VolumeOff(Application*& app)
{
	app->GetSet()->SetMuteVolume(app->GetSet()->GetVolume());
	app->GetSet()->SetVolume(0);
	return 1;
}

bool VolumeOn(Application*& app)
{
	app->GetSet()->SetVolume(app->GetSet()->GetMuteVolume());
	app->GetSet()->SetMuteVolume(0);
	return 1;
}

void AddMusic(Application*& app, string name) {
	if (!app->CheckMusic(name))
		return;
	app->GetPlaylist()->AddMus(app->GetMusic(name));
	return;
}

void AddPodcast(Application*& app, string name) {
	if (!app->CheckPodc(name))
		return;
	app->GetPlaylist()->AddRec(app->GetPodcast(name));
	return;
}

void AddBand(Application*& app, string name) {
	if (!app->GetBand(name))
		return;
	app->GetPlaylist()->AddBand(app->GetBand(name));
	return;
}

void DelPodcast(Application*& app,string name ) {
	app->GetPlaylist()->DelPodc(name);
}

void DelMusic(Application*& app, string name) {
	app->GetPlaylist()->DelMus(name);
}

void TurnOnMusic(Application*& app, string name)
{
	if (!app->GetMusic(name))
		return;
	app->SetCurrent(app->GetMusic(name));
}

void TurnOnPodcast(Application*& app, string name)
{
	if (!app->GetPodcast(name))
		return;
	app->SetCurrent(app->GetPodcast(name));
}

void TurnOffRecord(Application*& app)
{
	app->SetCurrent(NULL);
}

void TurnOnMusicOnPlaylist(Application*& app, string name)
{
	if (!app->GetPlaylist()->GetMusic(name))
		return;
	app->SetCurrent(app->GetPlaylist()->GetMusic(name));
}

void TurnOnPodcastOnPlaylist(Application*& app, string name)
{
	if (!app->GetPlaylist()->GetPodcast(name))
		return;
	app->SetCurrent(app->GetPlaylist()->GetPodcast(name));
}

void TurnOnNextPodcast(Application*& app)
{
	string name = app->GetCurrent()->GetName();
	app->SetCurrent(app->GetPlaylist()->GetNextPodcast(name));
}

void TurnOnNextMusic(Application*& app)
{
	string name = app->GetCurrent()->GetName();
	app->SetCurrent(app->GetPlaylist()->GetNextMusic(name));
}

void TurnOnAlbumOfBandOnPlaylist(Application*& app, string nameOfBand,string nameOfAlbum)
{
	if (!app->GetPlaylist()->GetBand(nameOfBand))
		return;
	if (!app->GetPlaylist()->GetBand(nameOfBand)->GetAlbum(nameOfAlbum))
		return;
	app->SetCurrent(app->GetPlaylist()->GetBand(nameOfBand)->GetAlbum(nameOfAlbum)->GetFirstSong());
}