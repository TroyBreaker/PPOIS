﻿#include <iostream>
#include <gtest/gtest.h>
//#include"Application.h"
#include "Methods.h"

TEST(TestCaseName, TestSettings) {
    Playlist* playlist = new Playlist;
    Settings* settings = new Settings;
    Application* app = new Application{ "Olegify",playlist,settings };
    vector<Music*> AllMusics;
    vector<Podcast*>AllPodcasts;
    vector <string> popular_songs = {
          "Shape of You",
              "Despacito",
              "Blinding Lights",
              "Uptown Funk",
              "Party Rock Anthem",
              "Old Town Road",
              "Thinking Out Loud",
              "Closer",
              "Sorry",
              "Rolling in the Deep",
              "Believer",
              "Havana",
              "Radioactive",
              "Starboy",
              "Happy",
              "Can't Stop the Feeling!",
              "Someone Like You",
              "All About That Bass",
              "Roar",
              "Bad Guy",
              "Hotline Bling",
              "Waka Waka",
              "Gangnam Style",
              "Hello",
              "Counting Stars",
              "Shake It Off",
              "Sugar",
              "Baby",
              "Love Yourself"
    };
    vector<string> popularPodcasts = {
         "The Joe Rogan Experience",
         "Serial",
         "The Daily",
         "Stuff You Should Know",
         "TED Radio Hour",
         "How I Built This",
         "Radiolab",
         "Crime Junkie",
         "The Dave Ramsey Show",
         "My Favorite Murder",
         "The Moth",
         "The Michelle Obama Podcast",
         "Armchair Expert with Dax Shepard",
         "Call Her Daddy",
         "The Ben Shapiro Show",
         "The Tony Robbins Podcast",
         "Conan O'Brien Needs a Friend",
         "Oprah's SuperSoul Conversations",
         "WorkLife with Adam Grant",
         "Unlocking Us with Brene Brown",
         "The Indicator from Planet Money",
         "The Happiness Lab with Dr. Laurie Santos",
         "Revisionist History",
         "The Smart Passive Income Online Business and Blogging Podcast",
         "Science Vs",
         "The Tim Ferriss Show",
         "Pod Save America",
         "The GaryVee Audio Experience",
         "The School of Greatness with Lewis Howes",
         "Hidden Brain",
         "The Bill Simmons Podcast"
    };
    for (int i = 0; i < 20; i++)
    {
        string line = popular_songs[i];
        double dlina1 = rand() % 7;
        double dlina2 = (rand() % 60 - 1) * 0.01;
        double dlina = dlina1 + dlina2;
        Music* mus = new Music("Classic", dlina, line);
        AllMusics.push_back(mus);
    }
    app->SetListOfMusic(AllMusics);

    for (int i = 0; i < 20; i++)
    {
        string line = popularPodcasts[i];
        double dlina1 = rand() % 7;
        double dlina2 = (rand() % 60 - 1) * 0.01;
        dlina1 += dlina2;
        Podcast* podc = new Podcast("James", "Amuse", dlina1, line);
        AllPodcasts.push_back(podc);
    }
    app->SetListOfPodcast(AllPodcasts);
    string line;
    AllPodcasts[0]->GetInfo(line);
    line = "";
    AllMusics[0]->GetInfo(line);

    vector<Album*>albums;
    for (int i = 0; i < 8;)
    {
        Album* album = new Album("FromHell");
        if (i < 2)
        {
            for (; i < 2; i++)
            {
                album->AddMusic(AllMusics[i]);
            }
            albums.push_back(album);
        }
        else
            if (i < 4)
            {
                for (; i < 4; i++)
                {
                    album->AddMusic(AllMusics[i]);
                }
                albums.push_back(album);
            }
            else
                if (i < 6)
                {
                    for (; i < 6; i++)
                    {
                        album->AddMusic(AllMusics[i]);
                    }
                    albums.push_back(album);
                }
                else
                    if (i < 8)
                    {
                        for (; i < 8; i++)
                        {
                            album->AddMusic(AllMusics[i]);
                        }
                        albums.push_back(album);
                    }
    }
    Band* banda1 = new Band("Lohs");
    Band* banda2 = new Band("Bulls");
    banda1->SetAlbums(albums[0]);
    banda1->SetAlbums(albums[1]);
    banda2->SetAlbums(albums[2]);
    banda2->SetAlbums(albums[3]);
    app->AddBand(banda1);
    app->AddBand(banda2);

    ApplicationOn(app);
    EXPECT_TRUE(app->GetState());
    IncreaseVolume(app, 50);
    EXPECT_EQ(80,app->GetSettings()->GetVolume());
    ReduceVolume(app, 60);
    EXPECT_EQ(20, app->GetSettings()->GetVolume());
    VolumeOff(app);
    EXPECT_EQ(0, app->GetSettings()->GetVolume());
    VolumeOn(app);
    EXPECT_EQ(20, app->GetSettings()->GetVolume());
    ApplicationOff(app);
    EXPECT_TRUE(!app->GetState());
}

TEST(TestCaseName, TestAdding) {
    Playlist* playlist = new Playlist;
    Settings* settings = new Settings;
    Application* app = new Application{ "Olegify",playlist,settings };
    vector<Music*> AllMusics;
    vector<Podcast*>AllPodcasts;
    vector <string> popular_songs = {
          "Shape of You",
              "Despacito",
              "Blinding Lights",
              "Uptown Funk",
              "Party Rock Anthem",
              "Old Town Road",
              "Thinking Out Loud",
              "Closer",
              "Sorry",
              "Rolling in the Deep",
              "Believer",
              "Havana",
              "Radioactive",
              "Starboy",
              "Happy",
              "Can't Stop the Feeling!",
              "Someone Like You",
              "All About That Bass",
              "Roar",
              "Bad Guy",
              "Hotline Bling",
              "Waka Waka",
              "Gangnam Style",
              "Hello",
              "Counting Stars",
              "Shake It Off",
              "Sugar",
              "Baby",
              "Love Yourself"
    };
    vector<string> popularPodcasts = {
         "The Joe Rogan Experience",
         "Serial",
         "The Daily",
         "Stuff You Should Know",
         "TED Radio Hour",
         "How I Built This",
         "Radiolab",
         "Crime Junkie",
         "The Dave Ramsey Show",
         "My Favorite Murder",
         "The Moth",
         "The Michelle Obama Podcast",
         "Armchair Expert with Dax Shepard",
         "Call Her Daddy",
         "The Ben Shapiro Show",
         "The Tony Robbins Podcast",
         "Conan O'Brien Needs a Friend",
         "Oprah's SuperSoul Conversations",
         "WorkLife with Adam Grant",
         "Unlocking Us with Brene Brown",
         "The Indicator from Planet Money",
         "The Happiness Lab with Dr. Laurie Santos",
         "Revisionist History",
         "The Smart Passive Income Online Business and Blogging Podcast",
         "Science Vs",
         "The Tim Ferriss Show",
         "Pod Save America",
         "The GaryVee Audio Experience",
         "The School of Greatness with Lewis Howes",
         "Hidden Brain",
         "The Bill Simmons Podcast"
    };
    for (int i = 0; i < 20; i++)
    {
        string line = popular_songs[i];
        double dlina1 = rand() % 7;
        double dlina2 = (rand() % 60 - 1) * 0.01;
        double dlina = dlina1 + dlina2;
        Music* mus = new Music("Classic", dlina, line);
        AllMusics.push_back(mus);
    }
    app->SetListOfMusic(AllMusics);

    for (int i = 0; i < 20; i++)
    {
        string line = popularPodcasts[i];
        double dlina1 = rand() % 7;
        double dlina2 = (rand() % 60 - 1) * 0.01;
        dlina1 += dlina2;
        Podcast* podc = new Podcast("James", "Amuse", dlina1, line);
        AllPodcasts.push_back(podc);
    }
    app->SetListOfPodcast(AllPodcasts);
    string line;
    AllPodcasts[0]->GetInfo(line);
    line = "";
    AllMusics[0]->GetInfo(line);

    vector<Album*>albums;
    for (int i = 0; i < 8;)
    {
        Album* album = new Album("FromHell");
        if (i < 2)
        {
            for (; i < 2; i++)
            {
                album->AddMusic(AllMusics[i]);
            }
            albums.push_back(album);
        }
        else
            if (i < 4)
            {
                for (; i < 4; i++)
                {
                    album->AddMusic(AllMusics[i]);
                }
                albums.push_back(album);
            }
            else
                if (i < 6)
                {
                    for (; i < 6; i++)
                    {
                        album->AddMusic(AllMusics[i]);
                    }
                    albums.push_back(album);
                }
                else
                    if (i < 8)
                    {
                        for (; i < 8; i++)
                        {
                            album->AddMusic(AllMusics[i]);
                        }
                        albums.push_back(album);
                    }
    }
    Band* banda1 = new Band("Lohs");
    Band* banda2 = new Band("Bulls");
    banda1->SetAlbums(albums[0]);
    banda1->SetAlbums(albums[1]);
    banda2->SetAlbums(albums[2]);
    banda2->SetAlbums(albums[3]);
    app->AddBand(banda1);
    app->AddBand(banda2);

    AddMusic(app, "Uptown Funk");
    EXPECT_TRUE(app->GetPlaylist()->CheckMusic("Uptown Funk"));
    AddMusic(app, "Despacito");
    EXPECT_TRUE(app->GetPlaylist()->CheckMusic("Despacito"));
    AddMusic(app, "Roar");
    EXPECT_TRUE(app->GetPlaylist()->CheckMusic("Roar"));
    AddPodcast(app, "TED Radio Hour");
    EXPECT_TRUE(app->GetPlaylist()->CheckPodcast("TED Radio Hour"));
    AddPodcast(app, "WorkLife with Adam Grant");
    EXPECT_TRUE(app->GetPlaylist()->CheckPodcast("WorkLife with Adam Grant"));
    AddBand(app, "Bulls");
    EXPECT_TRUE(app->GetPlaylist()->CheckBand("Bulls"));
}


TEST(TestCaseName, TestDeleteAndTurnOnMusic) {
    Playlist* playlist = new Playlist;
    Settings* settings = new Settings;
    Application* app = new Application{ "Olegify",playlist,settings };
    vector<Music*> AllMusics;
    vector<Podcast*>AllPodcasts;
    vector <string> popular_songs = {
          "Shape of You",
              "Despacito",
              "Blinding Lights",
              "Uptown Funk",
              "Party Rock Anthem",
              "Old Town Road",
              "Thinking Out Loud",
              "Closer",
              "Sorry",
              "Rolling in the Deep",
              "Believer",
              "Havana",
              "Radioactive",
              "Starboy",
              "Happy",
              "Can't Stop the Feeling!",
              "Someone Like You",
              "All About That Bass",
              "Roar",
              "Bad Guy",
              "Hotline Bling",
              "Waka Waka",
              "Gangnam Style",
              "Hello",
              "Counting Stars",
              "Shake It Off",
              "Sugar",
              "Baby",
              "Love Yourself"
    };
    vector<string> popularPodcasts = {
         "The Joe Rogan Experience",
         "Serial",
         "The Daily",
         "Stuff You Should Know",
         "TED Radio Hour",
         "How I Built This",
         "Radiolab",
         "Crime Junkie",
         "The Dave Ramsey Show",
         "My Favorite Murder",
         "The Moth",
         "The Michelle Obama Podcast",
         "Armchair Expert with Dax Shepard",
         "Call Her Daddy",
         "The Ben Shapiro Show",
         "The Tony Robbins Podcast",
         "Conan O'Brien Needs a Friend",
         "Oprah's SuperSoul Conversations",
         "WorkLife with Adam Grant",
         "Unlocking Us with Brene Brown",
         "The Indicator from Planet Money",
         "The Happiness Lab with Dr. Laurie Santos",
         "Revisionist History",
         "The Smart Passive Income Online Business and Blogging Podcast",
         "Science Vs",
         "The Tim Ferriss Show",
         "Pod Save America",
         "The GaryVee Audio Experience",
         "The School of Greatness with Lewis Howes",
         "Hidden Brain",
         "The Bill Simmons Podcast"
    };
    for (int i = 0; i < 20; i++)
    {
        string line = popular_songs[i];
        double dlina1 = rand() % 7;
        double dlina2 = (rand() % 60 - 1) * 0.01;
        double dlina = dlina1 + dlina2;
        Music* mus = new Music("Classic", dlina, line);
        AllMusics.push_back(mus);
    }
    app->SetListOfMusic(AllMusics);

    for (int i = 0; i < 20; i++)
    {
        string line = popularPodcasts[i];
        double dlina1 = rand() % 7;
        double dlina2 = (rand() % 60 - 1) * 0.01;
        dlina1 += dlina2;
        Podcast* podc = new Podcast("James", "Amuse", dlina1, line);
        AllPodcasts.push_back(podc);
    }
    app->SetListOfPodcast(AllPodcasts);
    string line;
    AllPodcasts[0]->GetInfo(line);
    line = "";
    AllMusics[0]->GetInfo(line);

    vector<Album*>albums;
    for (int i = 0; i < 8;)
    {
        Album* album = new Album("FromHell");
        if (i < 2)
        {
            for (; i < 2; i++)
            {
                album->AddMusic(AllMusics[i]);
            }
            albums.push_back(album);
        }
        else
            if (i < 4)
            {
                for (; i < 4; i++)
                {
                    album->AddMusic(AllMusics[i]);
                }
                albums.push_back(album);
            }
            else
                if (i < 6)
                {
                    for (; i < 6; i++)
                    {
                        album->AddMusic(AllMusics[i]);
                    }
                    albums.push_back(album);
                }
                else
                    if (i < 8)
                    {
                        for (; i < 8; i++)
                        {
                            album->AddMusic(AllMusics[i]);
                        }
                        albums.push_back(album);
                    }
    }
    Band* banda1 = new Band("Lohs");
    Band* banda2 = new Band("Bulls");
    banda1->SetAlbums(albums[0]);
    banda1->SetAlbums(albums[1]);
    banda2->SetAlbums(albums[2]);
    banda2->SetAlbums(albums[3]);
    app->AddBand(banda1);
    app->AddBand(banda2);

    AddMusic(app, "Uptown Funk");
    AddMusic(app, "Despacito");
    AddMusic(app, "Roar");
    AddPodcast(app, "TED Radio Hour");
    AddPodcast(app, "WorkLife with Adam Grant");
    AddBand(app, "Bulls");

    DeleteMusicFromPlaylist(app, "Despacito");
    EXPECT_TRUE(!app->GetPlaylist()->CheckMusic("Despacito"));
    TurnOnMusic(app, "Starboy");
    EXPECT_EQ("Starboy", app->GetCurrent()->GetName());
    TurnOnMusicOnPlaylist(app, "Roar");
    EXPECT_EQ("Roar", app->GetCurrent()->GetName());
    TurnOnNextMusic(app);
}


TEST(TestCaseName, TestTurnOnPodcastAndAlbum) {
    Playlist* playlist = new Playlist;
    Settings* settings = new Settings;
    Application* app = new Application{ "Olegify",playlist,settings };
    vector<Music*> AllMusics;
    vector<Podcast*>AllPodcasts;
    vector <string> popular_songs = {
          "Shape of You",
              "Despacito",
              "Blinding Lights",
              "Uptown Funk",
              "Party Rock Anthem",
              "Old Town Road",
              "Thinking Out Loud",
              "Closer",
              "Sorry",
              "Rolling in the Deep",
              "Believer",
              "Havana",
              "Radioactive",
              "Starboy",
              "Happy",
              "Can't Stop the Feeling!",
              "Someone Like You",
              "All About That Bass",
              "Roar",
              "Bad Guy",
              "Hotline Bling",
              "Waka Waka",
              "Gangnam Style",
              "Hello",
              "Counting Stars",
              "Shake It Off",
              "Sugar",
              "Baby",
              "Love Yourself"
    };
    vector<string> popularPodcasts = {
         "The Joe Rogan Experience",
         "Serial",
         "The Daily",
         "Stuff You Should Know",
         "TED Radio Hour",
         "How I Built This",
         "Radiolab",
         "Crime Junkie",
         "The Dave Ramsey Show",
         "My Favorite Murder",
         "The Moth",
         "The Michelle Obama Podcast",
         "Armchair Expert with Dax Shepard",
         "Call Her Daddy",
         "The Ben Shapiro Show",
         "The Tony Robbins Podcast",
         "Conan O'Brien Needs a Friend",
         "Oprah's SuperSoul Conversations",
         "WorkLife with Adam Grant",
         "Unlocking Us with Brene Brown",
         "The Indicator from Planet Money",
         "The Happiness Lab with Dr. Laurie Santos",
         "Revisionist History",
         "The Smart Passive Income Online Business and Blogging Podcast",
         "Science Vs",
         "The Tim Ferriss Show",
         "Pod Save America",
         "The GaryVee Audio Experience",
         "The School of Greatness with Lewis Howes",
         "Hidden Brain",
         "The Bill Simmons Podcast"
    };
    for (int i = 0; i < 20; i++)
    {
        string line = popular_songs[i];
        double dlina1 = rand() % 7;
        double dlina2 = (rand() % 60 - 1) * 0.01;
        double dlina = dlina1 + dlina2;
        Music* mus = new Music("Classic", dlina, line);
        AllMusics.push_back(mus);
    }
    app->SetListOfMusic(AllMusics);

    for (int i = 0; i < 20; i++)
    {
        string line = popularPodcasts[i];
        double dlina1 = rand() % 7;
        double dlina2 = (rand() % 60 - 1) * 0.01;
        dlina1 += dlina2;
        Podcast* podc = new Podcast("James", "Amuse", dlina1, line);
        AllPodcasts.push_back(podc);
    }
    app->SetListOfPodcast(AllPodcasts);
    string line;
    AllPodcasts[0]->GetInfo(line);
    line = "";
    AllMusics[0]->GetInfo(line);

    vector<Album*>albums;
    for (int i = 0; i < 8;)
    {
        Album* album = new Album("FromHell");
        if (i < 2)
        {
            for (; i < 2; i++)
            {
                album->AddMusic(AllMusics[i]);
            }
            albums.push_back(album);
        }
        else
            if (i < 4)
            {
                for (; i < 4; i++)
                {
                    album->AddMusic(AllMusics[i]);
                }
                albums.push_back(album);
            }
            else
                if (i < 6)
                {
                    for (; i < 6; i++)
                    {
                        album->AddMusic(AllMusics[i]);
                    }
                    albums.push_back(album);
                }
                else
                    if (i < 8)
                    {
                        for (; i < 8; i++)
                        {
                            album->AddMusic(AllMusics[i]);
                        }
                        albums.push_back(album);
                    }
    }
    Band* banda1 = new Band("Lohs");
    Band* banda2 = new Band("Bulls");
    banda1->SetAlbums(albums[0]);
    banda1->SetAlbums(albums[1]);
    banda2->SetAlbums(albums[2]);
    banda2->SetAlbums(albums[3]);
    app->AddBand(banda1);
    app->AddBand(banda2);

    AddPodcast(app, "TED Radio Hour");
    AddPodcast(app, "WorkLife with Adam Grant");
    AddBand(app, "Bulls");

    TurnOnPodcast(app, "Oprah's SuperSoul Conversations");
    EXPECT_EQ("Oprah's SuperSoul Conversations", app->GetCurrent()->GetName());
    TurnOnPodcastOnPlaylist(app, "TED Radio Hour");
    EXPECT_EQ("TED Radio Hour", app->GetCurrent()->GetName());
    TurnOnNextPodcast(app);
    EXPECT_EQ("WorkLife with Adam Grant", app->GetCurrent()->GetName());
    DeletePodcastFomPlaylist(app, "TED Radio Hour");
    EXPECT_TRUE(!app->GetPlaylist()->CheckPodcast("TED Radio Hour"));
    TurnOnAlbumOfBandOnPlaylist(app, "Bulls", "FromHell");
    EXPECT_EQ("Party Rock Anthem", app->GetCurrent()->GetName());
    TurnOffRecord(app);
}
