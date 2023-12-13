#pragma once
/**
* @brief Class of Settings for Application
*/
class Settings {
	//! current value of volume
	int volume=30;
	int const maxVolume = 100;
	int const minVolume = 0;
	//! keep 0 if volume not turned off, keep value of volume if volume turned off
	int muteVolume=0;
public:
	int GetMaxVolume() const
	{
		return maxVolume;
	}
	int GetMinVolume() const
	{
		return minVolume;
	}
	void IncrVolume(int val) 
	{
		volume += val;
	}
	void RedVolume(int val) 
	{
		volume -= val;
	}
	void SetVolume(int volume) 
	{
		this->volume = volume;
	}
	int GetVolume() const
	{
		return volume;
	}
	void SetMuteVolume(int MuteVolume) 
	{
		this->muteVolume = MuteVolume;
	}
	int GetMuteVolume() const
	{
		return muteVolume;
	}
};