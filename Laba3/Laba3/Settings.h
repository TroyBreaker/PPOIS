#pragma once
/**
* @brief Class of Settings for Application
*/
class Settings {
	int volume=30;
	int MuteVolume=0;
public:
	void IncrVolume(int val) {
		volume += val;
	}
	void RedVolume(int val) {
		volume -= val;
	}
	void SetVolume(int volume) {
		this->volume = volume;
	}
	int GetVolume()
	{
		return volume;
	}
	void SetMuteVolume(int MuteVolume) {
		this->MuteVolume = MuteVolume;
	}
	int GetMuteVolume()
	{
		return MuteVolume;
	}
};